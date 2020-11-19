# @Author: zjt
# @Date:   23-Oct-2020
# @Email:  jianting112358@gmail.com
# @Filename: a.py
# @Last modified by:   zjt
# @Last modified time: 24-Oct-2020
while True:
    try:
        n = map(int, raw_input().strip().split())
        i = int(n)
        str = " AC"
        print("AC"+(i-1)*str)
    except EOFError:
        break
