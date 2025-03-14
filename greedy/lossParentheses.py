# 내가 놓친 부분:
'''


일단 무조건 -가 있으면 묶는게 가장작은(최소) 값이 나오게 된다.
'''


# 내가 캐치한 부분
'''

일단 내가 생각할 수 있는 부분은 우선 +랑 -을 기준으로 나눠야하니 split()를사용해야되는건 거의 95% 깔고 가는게 맞다.

그리고 -를 '최대한 활용'해야 최소값을 만들 수 있다.
'''

# 문제였던 부분
'''
해당 과정에서 경우의수를 직접 작성해보지 않아서 그리고 좀 더 깊게 작성해보지 않아서.. 생긴 문제 같다.

경우의수를 따지는데 너무 오래걸렸다.

#### 처음에 spilt()했을 때 숫자랑 연산자 구분해서 놓는 과정을 일단 진행했어서.. 거기서 부터 오래걸렸던 것 같다.

#### 실제 숫자 기반으로 경우의수를 체크하지 않고 코드 중심으로만 너무 생각해서 오래걸렸다.

(절차적으로 순서대로 생각하는게 문제였다 거기안에서 규칙이나 멀리 보는게 필요.)

'''

# 얻어가야되는 부분
'''

*일단 연산자가 중점으로 파악해야하는건 파악할 수 있어야함* 
(경우의수를 따지는데 일단 직접 케이스를 작성해보고, 경계값을 잘 작성해보는 능력)

(절차적으로 순서대로 생각하는게 문제였다 '거기안에서 규칙이나 멀리 보는게' 필요.) --> 멀리서 보자(막히고 시간이 걸리는 것 같으면)

예를 들어 연속적으로 - + - + 을 작성

--- +++
-- + -- ++ - ++

-+-- + --- +
--- + -- ++ -
정도 테스트해보면 되지 않았을까?


```paintext
 -(a+b) -(b+c) -(k+l)를 보고 -를 -를 빼고 나머지를 다 더한뒤 -를 붙이면 된다는 것을 이해할 수 있어야한다.((a+b + b+c + k+l) 한뒤에 -1곱하는게 가능하다. )
```
 
'''
