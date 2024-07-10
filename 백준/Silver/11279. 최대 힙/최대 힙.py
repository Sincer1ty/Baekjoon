import sys

T = int(sys.stdin.readline())

class Heap():
    node = []
    
    def head(self):
        if len(self.node):
            print(self.node[0])
        else:
            print(0)
    def put(self, v):
        self.node.append(int(v))
        idx = len(self.node) - 1

        while self.checkUp(idx):
            parent = (idx-1)//2

            self.node[idx], self.node[parent] = self.node[parent], self.node[idx]
            idx = parent



    def checkUp(self, idx):
        if idx <=0:
            return False
        parent =  (idx-1)//2

        if self.node[idx] > self.node[parent]:
            return True
        else:
            return False
    
    def checkDown(self, idx):

        left = 2*idx+1
        right = 2*idx+2

        max = idx

        if left <= len(self.node)-2:
            if self.node[max]<self.node[left]:
                max = left
        if right <= len(self.node)-2:
            if self.node[max]<self.node[right]:
                max = right 
        if max == idx:
            return
        self.node[idx], self.node[max] = self.node[max], self.node[idx]
        self.checkDown(max)

    def delete(self):
        if len(self.node):
            self.node[0] = self.node[len(self.node) -1]

            self.checkDown(0)

            self.node.pop()

arr = Heap()

for i in range(T):
    c = int(sys.stdin.readline())

    if c == 0:
        arr.head()
        arr.delete()
    else:
        arr.put(c)
    