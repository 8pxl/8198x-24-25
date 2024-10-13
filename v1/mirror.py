import shutil
import os
path = 'src/autons/'
cache = path + 'cache/'
side = input("sideToGenerate? ")
shutil.rmtree(cache)
os.mkdir(cache)
for file in os.listdir(path):
    if (file[:3] != side): continue
    shutil.move(path + file, cache+file)
    print(path + file)
    # f = open(path + file, 'r')
    # print(f.readlines())