places = [["POOOP", "OXXOX", "OPXPX", "OOXOX", "POXXP"], ["POOPX", "OXPXP", "PXXXO", "OXXXO", "OOOPP"], ["PXOPX", "OXOXP", "OXPXX", "OXXXP", "POOXX"], ["OOOXX", "XOOOX", "OOOXX", "OXOOX", "OOOOO"], ["PXPXP", "XPXPX", "PXPXP", "XPXPX", "PXPXP"]]
dx = [-1, 0, 1, 0]
dy = [0, -1, 0, 1]


def check(x, y, this_place):
    visited = [[0 for _ in range(5)] for _ in range(5)]
    _len = 0
    tmp1 = [[x, y]]
    tmp2 = [0]
    while (len(tmp1) > 0):
        x = tmp1[0][0]
        y = tmp1[0][1]
        tmp1.remove(tmp1[0])
        visited[x][y] = 1
        _len = tmp2[0]
        tmp2.remove(_len)
        
        if _len == 2:
            return 1

        for d in range(4):
            nx = x + dx[d]
            ny = y + dy[d]
            print(nx, ny)
            if (0 <= nx <= 4) and (0 <= ny <= 4):
                if visited[nx][ny] == 0:
                    if this_place[nx][ny] == 'P':
                        print("------p");
                        return 0
                    elif this_place[nx][ny] == 'O':
                        print("------o");
                        tmp1.append([nx, ny])
                        tmp2.append(_len+1)
    return 1
        
def solution(places):
    answer = []
    
    for i in range(5):
        print("<<<<<< ", i, " >>>>>>>")
        this_place = places[i]
        flag = 0
        for a in range(5):
            for b in range(5):
                if this_place[a][b] == 'P':
                    if check(a, b, this_place) == 0: 
                        flag = 1 
                        break
            if flag == 1:  
                break
        if flag == 1: 
            answer.append(0)
        else: 
            answer.append(1)
                    
    return answer

print(solution(places))