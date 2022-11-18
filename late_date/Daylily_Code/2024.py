from cgitb import reset


class Solution:
    def maxConsecutiveAnswers(self, answerKey: str, k: int) -> int:
        print(answerKey)

if __name__ == "__main__":
    answerKey = input()
    k = int(input())
    res = Solution() 
    # print(res.maxConsecutiveAnswers(answerKey,k))
    res.maxConsecutiveAnswers(answerKey,k)