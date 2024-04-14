#include <graphics.h>
#include<iostream>

using namespace std;

class Button{ //encapsulation
    private:
        int x1,y1,x2,y2;
    public:
        Button(int _xleft, int _yleftupper, int _xright, int _yrightbottom)//declare where is the butt
        {
            x1 = _xleft;
            y1 = _yleftupper;
            x2 = _xright;
            y2 = _yrightbottom;
        }
        bool clickonButtonORnot(int x,int y)//check whether the button is clicked or not
        {
            bool options;
            if((x>=x1 && x<=x2) && (y>=y1 && y<=y2)){
                options = TRUE;//if clicked, return true
            }
            else {
                options = FALSE;//else, return false
            }
            return options;//return true or false
        }
};

class Bullet{
    private:
        int CoorX=0;
        int CoorY = 0;
    public:
        void setCoorX(int x){
            CoorX = x;
        }
        void setCoorY(int y){
            CoorY = y;
        }
        void drawBullet(int r, int color,int cX, int cY){
            int centerX = cX+r;
            setcolor(color);
            setfillstyle(SOLID_FILL,color) ;
            circle(centerX, cY, 20);
            setCoorX(centerX);
            floodfill(centerX-1, cY-1, color);
        }  
        void undrawBullet(int r, int cX, int cY){
            setcolor(BLACK);
            setfillstyle(SOLID_FILL,BLACK) ;
            circle(cX+r, cY, 25);
            floodfill(cX, cY, BLACK);
        } 
        int getCoorX() {
            return CoorX;
        }
        int getCoorY() {
            return CoorY;
        }
};

class Defender{
    protected:
        int HP, damage, Coin;
        int DefendX, DefendY;
        Bullet bullet; //Composition
    public:
        virtual void drawBullet(int r,int cX, int cY){}//Polymorphism-virtual member function
        virtual void undrawBullet(int r,int cX,int cY){}
        virtual void setBulletX(int x) {}
        virtual int getBulletX() {return 0;}
        virtual void setBulletY(int y){}
        virtual int getBulletY() {return 0;}
        virtual void drawDefender(int topLX, int topLY, int BottomRX, int BottomRY, int BulletX, int BulletY ) {}
        virtual int getDamage() const{return 0;}
        virtual int getMoney()const{return 0;}
        
};

class Cat:public Defender{//Inheritance
    private:
        int catDamage = 6, catMoney = 25;
        int catBulletX = 0;
        int catBulletY = 0;
    public:
        void setBulletX(int x){//override the virtual function from parent class
            bullet.setCoorX(x);//directly call the bullet function without declare bullet object because of inheritance from parent class
        }
        void setBulletY(int y){
            bullet.setCoorY(y);
        }
        int getBulletX() {
           catBulletX = bullet.getCoorX();
           return catBulletX;
        }
        int getBulletY() {
            catBulletY = bullet.getCoorY();
            return catBulletY;
        }
        void drawDefender(int topLX, int topLY, int BottomRX, int BottomRY, int BulletX, int BulletY){
            setcolor(LIGHTGRAY);
            rectangle(topLX, topLY, BottomRX, BottomRY);
            setBulletX(BulletX);
            setBulletY(BulletY);
        }
        void drawBullet(int r,int cX, int cY){
            bullet.drawBullet(r,LIGHTGRAY,cX,cY);
            int centerX = cX+r;
            circle(centerX, cY, 20);
            setBulletX(centerX);
            setBulletY(cY);
        }
        void undrawBullet(int r, int cX, int cY){
           bullet.undrawBullet(r, cX, cY);
        }
        int getDamage() const{
            return catDamage;
        }
        int getMoney() const{
            return catMoney;
        }
    
};

class Snake:public Defender{//Inheritance
    private:
        int snakeDamage = 10, snakeMoney = 50;
        int snakeBulletX = 0;
        int snakeBulletY = 0;      
    public:
        void setBulletX(int x){
           bullet.setCoorX(x);
        }
        void setBulletY(int y){
            bullet.setCoorY(y);
        }
        int getBulletX() {
            snakeBulletX = bullet.getCoorX();
            return snakeBulletX;
        }
        int getBulletY() {
            snakeBulletY = bullet.getCoorY();
            return snakeBulletY;
        }
        void drawDefender(int topLX, int topLY, int BottomRX, int BottomRY, int BulletX, int BulletY){
            setcolor(LIGHTBLUE);
            rectangle(topLX, topLY, BottomRX, BottomRY);
            setBulletX(BulletX);
            setBulletY(BulletY);
        }
        void drawBullet(int r, int cX, int cY){
            bullet.drawBullet(r,LIGHTBLUE,cX,cY);
            int centerX = cX + r;
            circle(centerX, cY, 20);
            setBulletX(centerX);
            setBulletY(cY);
        }
        void undrawBullet(int r, int cX, int cY){
            bullet.undrawBullet(r,cX,cY);
        }
        int getDamage() const{
            return snakeDamage;
        }  
        int getMoney() const{
            return snakeMoney;
        }
};

class Owl:public Defender{//Inheritance
    private:
        int HP3, owlDamage = 20, owlMoney = 100;
        int owlBulletX = 0;
        int owlBulletY = 0;
    public:
        void setBulletX(int x){
           bullet.setCoorX(x);
        }
        void setBulletY(int y){
            bullet.setCoorY(y);
        }
        int getBulletX() {
            owlBulletX = bullet.getCoorX();
            return owlBulletX;
        }
        int getBulletY() {
            owlBulletY = bullet.getCoorY();
            return owlBulletY;
        }
        void drawDefender(int topLX, int topLY, int BottomRX, int BottomRY, int BulletX, int BulletY){
            setcolor(LIGHTMAGENTA);
            rectangle(topLX, topLY, BottomRX, BottomRY);
            setBulletX(BulletX);
            setBulletY(BulletY);
        }
        void drawBullet(int r, int cX, int cY){
            bullet.drawBullet(r,LIGHTMAGENTA,cX,cY);
            int centerX = cX + r;
            circle(centerX, cY, 20);
            setBulletX(centerX);
            setBulletY(cY);
        }
        void undrawBullet(int r, int cX, int cY){
           bullet.undrawBullet(r,cX,cY);
        }
        int getDamage() const{
            return owlDamage;
        }  
        int getMoney() const{
            return owlMoney;
        }
};

class Money{
    private:
        int total;
        int Money = 700;
    public:
        void DeductMoney(Defender *defender){
            Money = Money - defender->getMoney();
        }
        void showMoney(){
                char buffer[16] = {};
                itoa(Money, buffer,10);
                settextstyle(0,0,3);
                outtextxy(600,150,(char*)"Money: ");
                outtextxy(750,150,buffer);
        }       
};


class Invader{
    protected:
        int HP = 0, Coin;
        int Coor_X = 0 , Coor_Y=0;
    public:
        int getHP() const{
            return HP;}
        void InvCoins(int coins = 0){
           Coin = coins; }
        void setX_Coor(int x){
            Coor_X = x;}
        void drawMI() {};
        void drawMouse(int) {};
        void undrawMouse(int) {}; 
        int getX_Coor()const{
            return Coor_X;}
        void DeductHP(Defender *defender){
            HP = HP - defender->getDamage();}
        void setMiceY(int r){
           Coor_Y = r; 
        }
        int getMiceY() const{
            return Coor_Y;
        }
        
};

class Mouse1:public Invader{//Inheritance
    private:
        int HP1 =20;
        int CoordinateX = 0;       
    public:
        int cx ,cy ,r ,c ;
        Mouse1(){}
        Mouse1(int cx1, int cy1, int r1, int c1){
            cx = cx1;
            cy = cy1;
            r = r1;
            c = c1;
        }
        void drawMI(){
            setcolor(c);
            circle(cx,cy,r);
            setfillstyle(SOLID_FILL, c);
            floodfill(cx,cy,c);
        }
        void setCoor_X(int x){
            CoordinateX =x;
        } 
        void setMice_Y(int r){
            Invader::setMiceY(r);//call the function of parent class by using double colon(::) operator
        }
        void drawMouse(int i){
            int R = Invader::getMiceY();
            int drawX = 1445-i;
            setCoor_X(drawX);
            setcolor(YELLOW);
            setfillstyle(SOLID_FILL,YELLOW);
            setlinestyle(0,0,3);
            circle(drawX, R, 40);
            floodfill(drawX, R, YELLOW);
        }
        void undrawMouse(int i){
            int undrawX = 1445-i;
            setcolor(BLACK);
            setfillstyle(SOLID_FILL,BLACK);
            circle(undrawX, Coor_Y, 40);
            floodfill(undrawX,Coor_Y, BLACK);
        }
        int getHP() const{
            return HP1; 
        }
        int getX_Coor() const{
            return CoordinateX;
        }
        void DeductHP(Defender *defender){
            HP1 = HP1 - defender->getDamage();
        }

};

class Mouse2:public Invader{
    private:
        int HP2 = 25, CoordinateX=0;
    public:   
        int cx , cy , r, c;
        Mouse2(){}    
        Mouse2(int cx2, int cy2, int r2, int c2){
            cx = cx2;
            cy = cy2;
            r = r2;
            c = c2;
        }
        void drawMI(){
            setcolor(c);
            circle(cx,cy,r);
            setfillstyle(SOLID_FILL, c);
            floodfill(cx,cy,c);
        }
        void setCoor_X(int x){
            CoordinateX =x;
        } 
        void setMice_Y(int r){
            Invader::setMiceY(r);
        }
        void drawMouse(int i){
            int R = Invader::getMiceY();
            int drawX = 1445-i;
            setCoor_X(drawX);
            setcolor(LIGHTGREEN);
            setfillstyle(SOLID_FILL,LIGHTGREEN);
            setlinestyle(0,0,3);
            circle(drawX, R, 40);
            floodfill(drawX, R, LIGHTGREEN);
        }
        void undrawMouse(int i){
            int undrawX = 1445-i;
            setcolor(BLACK);
            setfillstyle(SOLID_FILL,BLACK);
            circle(undrawX, Coor_Y, 40);
            floodfill(undrawX,Coor_Y, BLACK);
        }
        int getHP() const{
            return HP2; 
        }
        int  getX_Coor() const{
            return CoordinateX;
        }
        void DeductHP(Defender *defender){
            HP2 = HP2 - defender->getDamage();
        }
};

class Mouse3:public Invader{
    private:
        int HP3 = 36, CoordinateX=0;
    public:
        int cx, cy, r, c;
        Mouse3(){}
        Mouse3(int cx3, int cy3, int r3, int c3){
            cx = cx3;
            cy = cy3;
            r = r3;
            c = c3;
        }
        void drawMI(){
            setcolor(c);
            circle(cx,cy,r);
            setfillstyle(SOLID_FILL, c);
            floodfill(cx,cy,c);
        }
        void setCoor_X(int x){
            CoordinateX =x;
        } 
        void setMice_Y(int r){
            Invader::setMiceY(r);
        }
        void drawMouse(int i){
            int R = Invader::getMiceY();
            int drawX = 1445-i;
            setCoor_X(drawX);
            setcolor(LIGHTRED);
            setfillstyle(SOLID_FILL,LIGHTRED);
            setlinestyle(0,0,3);
            circle(drawX, R, 40);
            floodfill(drawX, R, LIGHTRED);
        }
        void undrawMouse(int i){
            int undrawX = 1445-i;
            setcolor(BLACK);
            setfillstyle(SOLID_FILL,BLACK);
            circle(undrawX, Coor_Y, 40);
            floodfill(undrawX,Coor_Y, BLACK);
        }
        int getHP() const{
            return HP3; 
        }
        int  getX_Coor() const{
            return CoordinateX;
        }
        void DeductHP(Defender *defender){
            HP3 = HP3 - defender->getDamage();
        }

};
class Map{
    private:
        int MouseCoorX;
        int MouseCoorY;
        Mouse1 *mouse1;//Aggregation
        Mouse2 *mouse2;//declare object pointer
        Mouse3 *mouse3;
    public:
        void drawMouseIcon1(Mouse1 *m1){//pass obejct pointer as an argument of a function
            mouse1 = m1;
            mouse1->drawMI();//call the function by using arrow(->) operator
        }
        void drawMouseIcon2(Mouse2 *m2){
            mouse2 = m2;
            mouse2->drawMI();
        }
        void drawMouseIcon3(Mouse3 *m3){
            mouse3 = m3;
            mouse3->drawMI();
        }
        void displayMap(){
            int x=275;
            setcolor(GREEN);
            setlinestyle(1, 0 ,3);
            line(128, 200, 1517, 200);
            line(128, 400, 1517, 400);
            line(128, 600, 1517, 600);
            line(128, 798, 1517, 798);
            line(128, 200, 128, 800);
            line(1517,200,1517,800);
            for(int a=0; a<9;a++){
                line(x,196,x,204);
                line(x,396,x,404);
                line(x,596,x,604);
                line(x,796,x,804);
                x+=138;
            }
            setcolor(YELLOW);
            line(413,196,413,204);
            line(413,396,413,404);
            line(413,596,413,604);
            line(413,796,413,804);
        }
        
        void Icon(){
            //cat
            setcolor(LIGHTGRAY);
            setlinestyle(0,0,3);
            rectangle(155,50,250,150);
            settextstyle(8,  0, 1);
            setcolor(YELLOW);
            outtextxy(185, 90, (char*)"CAT");
            //snake
            setcolor(LIGHTBLUE);
            setlinestyle(0,0,3);
            rectangle(300,50,395,150);
            settextstyle(8,  0, 1);
            setcolor(YELLOW);
            outtextxy(320, 90,(char*) "SNAKE");
            //owl
            setcolor(LIGHTMAGENTA);
            setlinestyle(0,0,3);
            rectangle(445,50,540,150);
            settextstyle(8,  0, 1);
            setcolor(YELLOW);
            outtextxy(475, 90, (char*)"OWL");
            //start button
            setcolor(RED);
            setlinestyle(0,0,3);
            rectangle(1350,50,1490,130);
            settextstyle(8,  0, 2);
            setcolor(YELLOW);
            outtextxy(1385, 80, (char*)"Start!");
        }      
};

void wait_for_left_click()
{
    const int DELAY = 50; // Milliseconds of delay between checks
    while (!ismouseclick(WM_LBUTTONDOWN))
        delay(DELAY);
}

void displayMI(){ //Aggregation
    Mouse1 M1 = Mouse1(976,90, 40 ,14);
    Mouse2 M2(1114, 90, 40, 10);
    Mouse3 M3(1252,90,40,12);
    Map *mapp;
    mapp->drawMouseIcon1(&M1);
    setcolor(YELLOW);
    outtextxy(936,150,(char*)"MOUSE 1");
    mapp->drawMouseIcon2(&M2);
    setcolor(LIGHTGREEN);
    outtextxy(1074,150,(char*)"MOUSE 2");
    mapp->drawMouseIcon3(&M3);
    setcolor(LIGHTRED);
    outtextxy(1212,150,(char*)"MOUSE 3");
}

void mainpage(){
L1:
    setbkcolor(BLACK);
    cleardevice();
    readimagefile("res/Battle of Animals.jpg",0,0,1600,850);

    bool choiceback=FALSE;
    bool choice;
    int x,y;
    Button start(982,651,1483,793);
    Button howtoplay(10,18,228,139);
    Button quit(25,707,241,811);
    Button back(1207,747,1467,779); 

    do{
        wait_for_left_click();
        getmouseclick(WM_LBUTTONDOWN, x, y);
        
        if(start.clickonButtonORnot(x,y)){
            choice = TRUE;
            }
        else if(howtoplay.clickonButtonORnot(x,y))
        {
            cleardevice();
            readimagefile("res/How to Play.jpg",0,0,1570,850);
            do{
                wait_for_left_click();
                getmouseclick(WM_LBUTTONDOWN, x, y);
                if(back.clickonButtonORnot(x,y)){
                    choiceback = TRUE;
                    goto L1;
                }
            }while(choiceback == FALSE);
            }
            else if(quit.clickonButtonORnot(x,y)){
                choice = TRUE;
                exit(1);
            }
            else {
                choice = FALSE;
            }  
        } while(choice == FALSE);
        cleardevice();
}

int putdefender(int &x, int &y)
{   
    if((x>=128 && x<=275)&&(y>=200 && y<=400)){//row1 column1
        return 0;
    }
    else if((x >= 276 && x<= 415)&&(y>=200 && y<=400)){//row1 column2     
        return 1; 
    }
    //second row
    else if((x>=128 && x<275)&&(y>=400 && y<=600)){//row2 column1      
        return 2;
    }
    else if((x>=276&& x<=415)&&(y>=400 && y<=600)){//row2 column2    
        return 3;
    }
    //third row
    else if((x>=128 && x<=275)&&(y>=600 && y<=800)){//row3 column1
        return 4;
    }
    else if((x>=276 && x<=415)&&(y>=600 && y<=800)){//row3 column2
        return 5;   
    }
    else {
        return 1000000;//to avoid the warning "does not return int"
    }
}

void displayResult(){
    settextstyle(0,0,3);
    setcolor(LIGHTCYAN);
    outtextxy(610,90,(char*)"You Win!!!!!");
}

void Play(){
    Defender *defender[6] = {NULL, NULL, NULL, NULL, NULL, NULL};
    Cat cat[10];
    Snake snake[10];
    Owl owl[10];    
    Mouse1 mouse1;
    Mouse2 mouse2;
    Mouse3 mouse3;
    Button buttonCat(155, 50, 250, 150);
    Button buttonSnake(300, 50, 395,150);
    Button buttonOwl(445,50, 540, 150);
    Button buttonStart(1350,50,1490,130);
    Money money;
    bool startOrNotStart;
   
    int x, y;   
    int a=0,b=1,c=2;
    int count = 0;
    do{       
        money.showMoney();
        int index = 0;
        wait_for_left_click();
        getmouseclick(WM_LBUTTONDOWN, x, y);
        if(buttonCat.clickonButtonORnot(x,y)){
            startOrNotStart = FALSE;
            wait_for_left_click();
            getmouseclick(WM_LBUTTONDOWN, x,y);
            if((x>128 && x<=414)&&(y>200&&y<=799)){
                index = putdefender(x,y);
                if(defender[index] == NULL){
                    if( (x>128 && x<275) && (y>200&&y<400) ){// row 1 column 1*
                        index = 0;
                        cat[index].drawDefender(155,240,230,360,250,300);
                        defender[index] = &cat[index];
                        money.DeductMoney(&cat[index]);
                        money.showMoney();
                        count ++; 
                    }
                    else if( (x>275 && x<415) && (y>200&&y<400)){// row 1 column 2*
                        index = 1;
                        cat[index].drawDefender(300,240,372,360,395,300);  
                        defender[index] = &cat[index];   
                        money.DeductMoney(&cat[index]);
                        money.showMoney();
                        count ++;
                    }
                    else if( (x>128 && x<275) && (y>400&&y<600)){// row 2 column 1*
                        index = 2;
                        cat[index].drawDefender(155,440,230,560,250,500);                        
                        defender[index] = &cat[index];  
                        money.DeductMoney(&cat[index]);
                        money.showMoney();
                        count ++;
                    }
                    else if( (x>275 && x<415) && (y>400&&y<600)){// row 2 column 2*
                        index = 3;
                        cat[index].drawDefender(300,440,372,560,395,500);                       
                        defender[index] = &cat[index];
                        money.DeductMoney(&cat[index]);
                        money.showMoney();
                        count++;   
                    }
                    else if( (x>128 && x<275) && (y>600&&y<800)){// row 3 column 1
                    index = 4;
                        cat[index].drawDefender(155,640,230,760,250,700);                       
                        defender[index] = &cat[index];
                        money.DeductMoney(&cat[index]);
                        money.showMoney();   
                        count ++;
                    }
                    else if( (x>275 && x<415) && (y>600&&y<800)){// row 3 column 2
                        index = 5;
                        cat[index].drawDefender(300,640,372,760,395,700);                      
                        defender[index] = &cat[index]; 
                        money.DeductMoney(&cat[index]);
                        money.showMoney();
                        count ++;  
                    }
                }
            }    
        }
        else if(buttonSnake.clickonButtonORnot(x,y)){
            startOrNotStart = FALSE;
            wait_for_left_click();
            getmouseclick(WM_LBUTTONDOWN, x,y);
            if((x>128 && x<=414)&&(y>200&&y<=799)){
                index = putdefender(x,y);
                if(defender[index] == NULL){
                    if( (x>128 && x<275) && (y>200&&y<400) ){// row 1 column 1*
                        index = 0;
                        snake[index].drawDefender(155,240,230,360,250,300);
                        defender[index] = &snake[index];
                        money.DeductMoney(&snake[index]);
                        money.showMoney();
                        count ++;  
                    }
                    else if( (x>275 && x<415) && (y>200&&y<400)){ // row 1 column 2*
                        index = 1;
                        snake[index].drawDefender(300,240,372,360,395,300);  
                        defender[index] = &snake[index];
                        money.DeductMoney(&snake[index]);
                        money.showMoney();
                        count ++;
                    }
                    else if( (x>128 && x<275) && (y>400&&y<600)){// row 2 column 1*
                        index = 2;
                        snake[index].drawDefender(155,440,230,560,250,500);                       
                        defender[index] = &snake[index];
                        money.DeductMoney(&snake[index]);
                        money.showMoney();  
                        count ++;
                    }
                    else if( (x>275 && x<415) && (y>400&&y<600)){// row 2 column 2*
                        index = 3;
                        snake[index].drawDefender(300,440,372,560,395,500);                       
                        defender[index] = &snake[index]; 
                        money.DeductMoney(&snake[index]);
                        money.showMoney(); 
                        count++; 
                    }
                    else if( (x>128 && x<275) && (y>600&&y<800)){// row 3 column 1
                        index = 4;
                        snake[index].drawDefender(155,640,230,760,250, 700);       
                        defender[index] = &snake[index];  
                        money.DeductMoney(&snake[index]);
                        money.showMoney(); 
                        count++;
                    }
                    else if( (x>275 && x<415) && (y>600&&y<800)){// row 3 column 2
                        index = 5;
                        snake[index].drawDefender(300,640,372,760,395,700);                      
                        defender[index] = &snake[index];  
                        money.DeductMoney(&snake[index]);
                        money.showMoney();  
                        count++;
                    }
                }
            }
        }
        else if(buttonOwl.clickonButtonORnot(x,y)){
            startOrNotStart = FALSE;
            wait_for_left_click();
            getmouseclick(WM_LBUTTONDOWN, x,y);
            if((x>128 && x<=414)&&(y>200&&y<=799)){
                index = putdefender(x,y);
                if(defender[index] == NULL){
                    if( (x>128 && x<275) && (y>200&&y<400) ){// row 1 column 1*
                        index = 0;
                        owl[index].drawDefender(155,240,230,360,250,300);
                        defender[index] = &owl[index]; 
                        money.DeductMoney(&owl[index]);
                        money.showMoney(); 
                        count++;
                    }
                    else if( (x>275 && x<415) && (y>200&&y<400)){ // row 1 column 2*
                        index = 1;
                        owl[index].drawDefender(300,240,372,360,395,300);  
                        defender[index] = &owl[index];  
                        money.DeductMoney(&owl[index]);
                        money.showMoney(); 
                        count++; 
                    }
                    else if( (x>128 && x<275) && (y>400&&y<600)){// row 2 column 1*
                        index = 2;
                        owl[index].drawDefender(155,440,230,560,250,500);                       
                        defender[index] = &owl[index]; 
                        money.DeductMoney(&owl[index]);
                        money.showMoney();  
                        count++;
                    }
                    else if( (x>275 && x<415) && (y>400&&y<600)){// row 2 column 2*
                        index = 3;
                        owl[index].drawDefender(300,440,372,560,395,500);                       
                        defender[index] = &owl[index]; 
                        money.DeductMoney(&owl[index]);
                        money.showMoney(); 
                        count++;  
                    }
                    else if( (x>128 && x<275) && (y>600&&y<800)){// row 3 column 1
                        index = 4;
                        owl[index].drawDefender(155,640,230,760,250,700);       
                        defender[index] = &owl[index]; 
                        money.DeductMoney(&owl[index]);
                        money.showMoney();  
                        count++; 
                    }
                    else if( (x>275 && x<415) && (y>600&&y<800)){// row 3 column 2
                        index = 5;
                        owl[index].drawDefender(300,640,372,760,395,700);                      
                        defender[index] = &owl[index];  
                        money.DeductMoney(&owl[index]);
                        money.showMoney(); 
                        count++; 
                    }
                }
            }
        } 
        else if(buttonStart.clickonButtonORnot(x,y) && count == 6){
            setcolor(BLACK);
            settextstyle(0, 0, 0);
            outtextxy(590,90,(char*)"PLEASE PLACE 6 DEFENDERS!");
            startOrNotStart = TRUE;
        }
        else if(buttonStart.clickonButtonORnot(x,y) && count < 6){
            settextstyle(0, 0, 0);
            outtextxy(590,90,(char*)"PLEASE PLACE 6 DEFENDERS!");}
       
    } while(startOrNotStart == FALSE);         

    //wave 1 lane1
    int moveMouseForwardL1 = 0;   
    int moveBulletForwardL1 = 0;

    int bulletCoorL1X0 = defender[0]->getBulletX();
    int bulletCoorL1Y0 = defender[0]->getBulletY();
    int bulletCoorL1X1 = defender[1]->getBulletX();
    int bulletCoorL1Y1 = defender[1]->getBulletY();

    mouse1.setCoor_X(1500);
    mouse1.setMice_Y(300);

    int mouse1X = mouse1.getX_Coor();
    int mouseCoorY = mouse1.getMiceY();

    int mouse1HP = mouse1.getHP();

    //mouse  and bullet move
    while(mouse1HP>0){
        if(bulletCoorL1Y0 == mouseCoorY){
            if(bulletCoorL1Y1 == mouseCoorY){
                 int bulletX0 = bulletCoorL1X0;
                 int bulletX1 = bulletCoorL1X1;
            moveBulletForwardL1 = 150;  
            while ((bulletX0<=mouse1X) ||(bulletX1<=mouse1X)){          
                mouse1.drawMouse(moveMouseForwardL1);
                delay(200);
                mouse1.undrawMouse(moveMouseForwardL1);
                delay(200);
                defender[0]->drawBullet(moveBulletForwardL1,bulletX0, bulletCoorL1Y0);
                delay(200);
                defender[0]->undrawBullet(moveBulletForwardL1, bulletX0, bulletCoorL1Y0);
                delay(200);
                if(bulletX1<=mouse1X){
                    defender[1]->drawBullet(moveBulletForwardL1,bulletX1, bulletCoorL1Y1);
                    delay(200);
                    defender[1]->undrawBullet(moveBulletForwardL1, bulletX1, bulletCoorL1Y1);
                    delay(200); 
                }
                else {
                    defender[1]->undrawBullet(moveBulletForwardL1, bulletX1, bulletCoorL1Y1);
                    delay(200);
                }
            
                moveMouseForwardL1 +=50; 
                bulletX0 = moveBulletForwardL1 + bulletX0;
                bulletX1 = moveBulletForwardL1 + bulletX1;
                
                mouse1X = mouse1.getX_Coor();
                bulletX0 = defender[0]->getBulletX();  
                bulletX1 = defender[1]->getBulletX();      
            }    
            defender[0]->undrawBullet(moveBulletForwardL1, bulletX0, bulletCoorL1Y0);
            mouse1.DeductHP(defender[1]);
            mouse1.DeductHP(defender[0]);
            mouse1HP = mouse1.getHP();  
            }                 
        }
        else{
            mouse1.drawMouse(moveMouseForwardL1);
            delay(200);
            mouse1.undrawMouse(moveMouseForwardL1);
            delay(200);
            moveMouseForwardL1 +=50; 
        }
    }

    //wave 1 lane2
    int moveMouseForwardL2 = 0;   
    int moveBulletForwardL2 = 0;

    int bulletCoorL2X0 = defender[2]->getBulletX();
    int bulletCoorL2Y0 = defender[2]->getBulletY();
    int bulletCoorL2X1 = defender[3]->getBulletX();
    int bulletCoorL2Y1 = defender[3]->getBulletY();

    mouse2.setCoor_X(1500);
    mouse2.setMice_Y(500);

    int mouse2X = mouse2.getX_Coor();
    mouseCoorY = mouse2.getMiceY();
    int mouse2HP = mouse2.getHP();
    while(mouse2HP>0){
        if(bulletCoorL2Y0 == mouseCoorY){
            if(bulletCoorL2Y1 == mouseCoorY){
                 int bulletX0 = bulletCoorL2X0;
                 int bulletX1 = bulletCoorL2X1;
                moveBulletForwardL2 = 150;  
            while ((bulletX0<=mouse2X) ||(bulletX1<=mouse2X)){          
                mouse2.drawMouse(moveMouseForwardL2);   
                delay(200);
                mouse2.undrawMouse(moveMouseForwardL2);
                delay(200);
                defender[2]->drawBullet(moveBulletForwardL2,bulletX0, bulletCoorL2Y0);
                delay(200);
                defender[2]->undrawBullet(moveBulletForwardL2, bulletX0, bulletCoorL2Y0);
                delay(200);
                if(bulletX1>mouse2X){
                    defender[3]->undrawBullet(moveBulletForwardL2, bulletX1, bulletCoorL2Y1);
                    delay(200); 
                }
                else {
                    defender[3]->drawBullet(moveBulletForwardL2,bulletX1, bulletCoorL2Y1);
                    delay(200);
                    defender[3]->undrawBullet(moveBulletForwardL2, bulletX1, bulletCoorL2Y1);
                    delay(200); 
                }
            
                moveMouseForwardL2 +=50; 
                bulletX0 = moveBulletForwardL2 + bulletX0;
                bulletX1 = moveBulletForwardL2 + bulletX1;
                
                mouse2X = mouse2.getX_Coor();
                bulletX0 = defender[2]->getBulletX();  
                bulletX1 = defender[3]->getBulletX();      
            }    
            defender[2]->undrawBullet(moveBulletForwardL2, bulletX0, bulletCoorL2Y0);
            mouse2.DeductHP(defender[3]);
            mouse2.DeductHP(defender[2]);
            mouse2HP = mouse2.getHP();  
            }                 
        }
        else{
            mouse2.drawMouse(moveMouseForwardL2);
            delay(200);
            mouse2.undrawMouse(moveMouseForwardL2);
            delay(200);
            moveMouseForwardL2 +=50; 
        }
    }

    //wave 1 lane3
    int moveMouseForwardL3 = 0;   
    int moveBulletForwardL3 = 0;

    int bulletCoorL3X0 = defender[4]->getBulletX();
    int bulletCoorL3Y0 = defender[4]->getBulletY();
    int bulletCoorL3X1 = defender[5]->getBulletX();
    int bulletCoorL3Y1 = defender[5]->getBulletY();

    mouse3.setCoor_X(1500);
    mouse3.setMice_Y(700);

    mouse1X = mouse3.getX_Coor();
    mouseCoorY = mouse3.getMiceY();

    mouse1HP = mouse3.getHP();

    //mouse  and bullet move
    while(mouse1HP>0){
        if(bulletCoorL3Y0 == mouseCoorY){
            if(bulletCoorL3Y1 == mouseCoorY){
                 int bulletX0 = bulletCoorL3X0;
                 int bulletX1 = bulletCoorL3X1;
            moveBulletForwardL3 = 150;  
            while ((bulletX0<=mouse1X) ||(bulletX1<=mouse1X)){          
                mouse3.drawMouse(moveMouseForwardL3);
                delay(200);
                mouse3.undrawMouse(moveMouseForwardL3);
                delay(200);
                defender[4]->drawBullet(moveBulletForwardL3,bulletX0, bulletCoorL3Y0);
                delay(200);
                defender[4]->undrawBullet(moveBulletForwardL3, bulletX0, bulletCoorL3Y0);
                delay(200);
                if(bulletX1>mouse1X){
                    defender[5]->undrawBullet(moveBulletForwardL3, bulletX1, bulletCoorL3Y1);
                    delay(200); 
                }
                else {
                    defender[5]->drawBullet(moveBulletForwardL3,bulletX1, bulletCoorL3Y1);
                    delay(200);
                    defender[5]->undrawBullet(moveBulletForwardL3, bulletX1, bulletCoorL3Y1);
                    delay(200); 
                }
            
                moveMouseForwardL3 +=50; 
                bulletX0 = moveBulletForwardL3 + bulletX0;
                bulletX1 = moveBulletForwardL3 + bulletX1;
                
                mouse1X = mouse3.getX_Coor();
                bulletX0 = defender[4]->getBulletX();  
                bulletX1 = defender[5]->getBulletX();      
            }    
            defender[4]->undrawBullet(moveBulletForwardL3, bulletX0, bulletCoorL3Y0); 
            mouse3.DeductHP(defender[5]);
            mouse3.DeductHP(defender[4]);
            mouse1HP = mouse3.getHP();  
            }                 
        }
        else{
            mouse3.drawMouse(moveMouseForwardL3);
            delay(200);
            mouse3.undrawMouse(moveMouseForwardL3);
            delay(200);
            moveMouseForwardL3 +=50; 
        }
    }
    displayResult();
}

int main()
{
    initwindow(1600,900,"BOA");
    mainpage();

    Map map1;

    map1.displayMap();
    map1.Icon();
    displayMI();
    Play();
    //delay(5000);
    //exit(1);
     
    system ("pause");
    return 0;
}
