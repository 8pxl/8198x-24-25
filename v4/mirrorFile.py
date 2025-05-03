import shutil
import os
import re


path = "src/autons/pos/rrings.hpp"
write = "src/autons/pos/brings.hpp"
f = open(path, 'r')
w = open(write, 'w')

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