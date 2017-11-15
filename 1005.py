import re 
def func():
    S = sum(int(i) for i in re.findall(r'.{1}',input()))
    engnum = ["zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"]
    strS = [engnum[int(i)] for i in re.findall(r'.{1}',str(S))]
    print(' '.join(strS))

if __name__ == '__main__':
    func()
