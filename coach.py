class coach():
    no=72
    m=9
    seat=[0]*72
    def reserve(self):
        i=4
        count=0
        while(i<9):
            if(self.seat[i*8+3]==0):
                self.seat[i*8+3]=1
                break
            elif(self.seat[i*8]==0):
                self.seat[i*8]=1
                break
            elif(self.seat[i*8+6]==0):
                self.seat[i*8+6]=1
                break
            if(count%2==0):
                i=i+count+1
            else:
                i=i-count-1
            count=count+1




a= coach()
a.reserve()
a.reserve()
a.reserve()


for i in range(0,9):
    for j in range(0,8):
        print(a.seat[i*8+j] ,end="  ")
    print("\n")









