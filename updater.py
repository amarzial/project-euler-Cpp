import glob
import re
replace_string = '''    case({0}):
      std::cout << "Problem {0}:" << std::endl;
      start_t = std::chrono::system_clock::now();
      prob{0}::Start();
      end_t = std::chrono::system_clock::now();
      print_speed(end_t - start_t);
      if (not full_run) break;\n'''

f = open("template.cpp", 'r')
sources = glob.glob("./probs/prob*.cpp")
problems = []
for prob in sources:
    a = re.match("./probs/prob(\d+).cpp", prob)
    problems.append(a.group(1))

problems.sort()

out = open("start.cpp", 'w')
for line in f.readlines():
    if "$REPLACE$" in line:
        for prob in problems:
            out.write(replace_string.format(prob))
    else:
        out.write(line);
f.close()
out.close()

header = open("problems.hpp", 'w')
header.write("#ifndef PROBLEM_HPP\n#define PROBLEM_HPP\n\n")

for prob in problems:
    header.write("namespace prob{0} {{\n  int Start();\n}}\n".format(prob))
header.write("#endif\n")
header.close()
