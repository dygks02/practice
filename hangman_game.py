from random import randrange
lists = ["apple","banana","orange","peach","lemon"]
game = list(lists[randrange(0,len(lists))])
print("game start!")
life = 10
line = ["_" for i in range(0,len(game))]
picture = ["""
     __________
     |        |
     |        ㅇ
     |       \ | /    
     |         |
     |        / \.
     |
----------- ""","""
     __________
     |        |
     |        ㅇ
     |       \ | /    
     |         |
     |        / \.
     |
""","""
     __________
              |
              ㅇ
             \ | /    
               |
              / \.
     
""","""
     
              |
              ㅇ
             \ | /    
               |
              / \.
     
""","""
     
              
              ㅇ
             \ | /    
               |
              / \.
     
""","""
     
              
              
             \ | /    
               |
              / \.
     
""","""
     
              
              
               | /    
               |
              / \.
     
""","""
     
              
              
               |    
               |
              / \.
     
""","""
     
              
              
                
               
              / \.
     
""","""
     
              
              
                
               
                \.
     
""","""
     
              
     GAMEOVER!!!!!         
                
               
                """]
picture.reverse()          
           
  
while(True):
    print(" ".join(line))
    print(picture[life])
    p = input()
    k = 0
    index = -1
    if(p == "".join(game)):
        print("WOW!!!")
        break
    for i in game:
        if(p == i):
            index = "".join(game).find(i,index + 1)
            line[index] = game[index]
            k += 1
    if(k > 0):
        print("Nice!")
    else:
        print("fail")
        life -= 1
      
   
    if("".join(line).find("_") == -1 or life == 0):
        break



if(life == 0):
    print(picture[life])
print(" ".join(game))
print(f"life : {life}")
    
  
    



