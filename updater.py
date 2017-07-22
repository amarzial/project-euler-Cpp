import glob
import re
import sys

try:
    f = open(sys.argv[1], 'r')
except:
    print ("Invalid argument")
    exit()

sources = glob.glob("./prob/prob*.cpp")
problems = []
for prob in sources:
    a = re.match("./prob/prob(\d+).cpp", prob)
    problems.append(a.group(1))

problems.sort()

out = open("src/start.cpp", 'w')
replacing = False
replace_string = ""
for line in f.readlines():
    if "$TEMPLATE$" in line:
        replacing = True
    elif replacing:
        if "$END_TEMPLATE$" in line:
            replacing = False
            for prob in problems:
                out.write(replace_string.format(prob))
        else:
            replace_string += line;
    else:
        out.write(line);
f.close()
out.close()

header = open("include/problems.hpp", 'w')
header.write("#ifndef PROBLEM_HPP\n#define PROBLEM_HPP\n\n")

for prob in problems:
    header.write("namespace prob{0} {{\n  int Start();\n}}\n".format(prob))
header.write("#endif\n")
header.close()
