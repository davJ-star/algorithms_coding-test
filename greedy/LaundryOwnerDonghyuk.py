

length = int(input())
lst = []
moneys = [25, 10, 5, 1] # 일단 이게 되는 이유는 25를 만들수있으며, 10*2+5로 3개가 된다, 그러므로 25가 최소 개수가 됨
#money = 0 # 누적된다.

# 길이만큼 cent 받기
for _ in range(length):
  lst.append(int(input()))

# 받은 cent 처리하기
for idx, cent in enumerate(lst):
  print(f"{idx} - {cent}")
  print(f"moneys - {moneys[idx]}")
  # 각 해당 로직을 어떻게 작성할 것인가?
  if(cent // moneys[idx] == 0):
    break

  moneys[idx] //= cent
  cent %= moneys[idx]

  if(cent // moneys[++idx] == 0):
    break
  moneys[idx] //= cent
  cent %= moneys[idx]

  if(cent // moneys[++idx] == 0):
    break
  moneys[idx] //= cent
  cent %= moneys[idx]
  ## // 다할 필요없이 break도 있다.


