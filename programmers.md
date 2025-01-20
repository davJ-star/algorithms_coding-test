# lv0

### 
```python
def solution(a, b, flag):
    answer = 0 # 기본 조건이라서 가독성 살리는 방향으로 진행

    if flag:
        answer = a + b
    else :
        answer = a - b
    return answer


```

```python
def solution(a, b, flag):
    # 다만 간단하게 내용이면, 바로 진행하도록 한다. 다만 특히 많이 사용하는 경우 이렇게 한줄로 쓸수 있다. 
    return a + b if flag else a - b

```

```python
# 조금 더 생각해봐야겠다.
if break랑 동일하다고 생각하자: return 뒤에 더이상 실행할 것이 없을 때 break 와 같이 함수 단위에서 사용할 수 있는 것

# flag에 따라 다른 값 반환하기하기니깐 return에만 신경쓰면 되고 **return 의미는 끝나고 함수 탈출(종료)** --> 이니깐 동작 시뮬레이션해서 if 걸리면 그 아래는 실행이 안되고 끝나니깐 안걸릴때 return만 넣어주면 된다. **그뒤로 실행해야될 것이 없음.** 
def solution(a, b, flag):
    # return으로 함수 빠져나간다는 점 활용

    if flag:
        return a + b

    return a - b


```


![image](https://github.com/user-attachments/assets/556deb7a-8134-4517-a473-2ae91c8b2d3f)

#### 괜찮은 문제풀이
![image](https://github.com/user-attachments/assets/d10b1ad4-1888-4505-8f73-28d06cc2ecfe)
![image](https://github.com/user-attachments/assets/04c86762-cff5-4a23-8c99-6274ec49b5e6)


