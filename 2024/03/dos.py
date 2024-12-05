import re

def process(data):
    m_pattern = r"mul\((\d+),(\d+)\)"
    do_pattern = r"do\(\)"
    dont_pattern = r"don't\(\)"
    total = 0
    index = 0
    mul = True
    while index < len(data):
        if re.match(do_pattern, data[index:]):
            mul = True
            index += len(re.match(do_pattern, data[index:]).group(0))
        elif re.match(dont_pattern, data[index:]):
            mul = False
            index += len(re.match(dont_pattern, data[index:]).group(0))
        else:
            m_match = re.match(m_pattern, data[index:])
            if m_match and mul:
                x, y = int(m_match.group(1)), int(m_match.group(2))
                total += x * y
                index += len(m_match.group(0))
            else:
                index += 1
    return total

if __name__ == "__main__":
    with open("input.txt", "r") as f:
        data = f.read()
    result = process(data)
    print(result)
