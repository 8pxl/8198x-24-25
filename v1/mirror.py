import shutil
import os
import re

path = 'src/autons/'
cache = path + 'cache/'
side = input("sideToGenerate? ")
shutil.rmtree(cache)
os.mkdir(cache)
assert(side == "r" or side == "b")

points = r'(\{\s*(-?\d+(\.\d+)?),\s*(-?\d+(\.\d+)?)\s*\})'
turn = r'(?://.*|/\*.*?\*/|\s*).*?chass\.turn\(\s*([^,]+)'

def flipAng(ang):
    new = ang
    if '(' in ang:
        new = ang[4:][:-1]
    else:
        new = 'neg(' + ang + ')'
    return new

def grabNums(txt):
    return float(txt.replace('{', '').replace('}', ''))

for file in os.listdir(path):
    if (file[0] != side): continue
    shutil.move(path + file, cache+file)
    print(path + file)
for file in os.listdir(path):
    if file[0] != ('r' if side == 'b' else 'r'): continue
    f = open(path + file, 'r')
    w = open(path + side + file[1:], 'w')
    print(path+file)
    for line in f.readlines():
        toWrite = line
        matches = re.findall(points, line)
        if matches:
            assert(len(matches)==1)
            match = matches[0][0]
            # print(match)
            pt = list(map(grabNums, match.split(',')))
            new = '{' + str(-pt[0]) + ', ' + str(pt[1]) + '}'
            toWrite = line.replace(match, new)
        if "driveAngle" in line:
            func = (line.split(','))
            ang = (line.split(',')[1]).strip()
            if (ang[:3] == "imu"): continue
            angAdj = flipAng(ang)
            func[1] = ' ' + angAdj
            toWrite = ",".join(func)
        matches = re.findall(turn, line)
        if matches:
            assert(len(matches)==1)
            func = (line.split(','))
            func[0] = func[0].replace(matches[0], flipAng(matches[0]))
            toWrite = ",".join(func)
        w.write(toWrite)