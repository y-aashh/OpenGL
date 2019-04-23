#include<GLUT/glut.h>
#include<OpenGL/gl.h>
#include<OpenGL/glu.h>
#include<stdio.h>
float xt=0;
int flag=0;



void disp()
{
    glClear(GL_COLOR_BUFFER_BIT);


    glBegin(GL_POLYGON);
    glColor3f(0,0,1);
    glVertex2i(0+xt,300);
    glVertex2i(20+xt,300);
    glVertex2i(20+xt,370);
    glVertex2i(0+xt,370);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0,0,1);
    glVertex2i(20+xt,330);
    glVertex2i(20+xt,370);
    glVertex2i(80+xt,370);
    glVertex2i(80+xt,330);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0,0,1);
    glVertex2i(80+xt,300);
    glVertex2i(80+xt,440);
    glVertex2i(200+xt,440);
    glVertex2i(200+xt,300);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0,0,1);
    glVertex2i(200+xt,330);
    glVertex2i(200+xt,440);
    glVertex2i(260+xt,370);
    glVertex2i(260+xt,330);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0,0,1);
    glVertex2i(0+260+xt,300);
    glVertex2i(30+260+xt,300);
    glVertex2i(30+260+xt,370);
    glVertex2i(0+260+xt,370);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1,0,0);

    glVertex2i(-5+xt,330);
    glVertex2i(10+xt,330);
    glVertex2i(10+xt,355);
    glVertex2i(-5+xt,355);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1,1,0);

    glVertex2i(-5+280+xt,330);
    glVertex2i(10+280+xt,330);
    glVertex2i(10+280+xt,355);
    glVertex2i(-5+280+xt,355);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0,0,0);

    glVertex2i(200+xt,370);
    glVertex2i(200+xt,430);
    glVertex2i(250+xt,370);

    glEnd();

    glEnable(GL_POINT_SMOOTH);
    glPointSize(45);
    glBegin(GL_POINTS);
    glColor3f(0,0,0);
    glVertex2i(50+xt,300);
    glVertex2i(230+xt,300);
    glEnd();

    
    glLineWidth(10);
    glBegin(GL_LINES);

    glVertex2i(20+xt,300);
    glVertex2i(20+xt,330);

    glVertex2i(20+xt,330);
    glVertex2i(80+xt,330);

    glVertex2i(80+xt,330);
    glVertex2i(80+xt,300);

    glVertex2i(200+xt,300);
    glVertex2i(200+xt,330);

    glVertex2i(200+xt,330);
    glVertex2i(260+xt,330);

    glVertex2i(260+xt,330);
    glVertex2i(260+xt,300);


    glEnd();


    glFlush();
}
void mouse(int button,int state,int x,int y)
{
    if(state== GLUT_DOWN)
    {
        if(flag==0)
        flag = 1;  
        else
        flag=0;  
    }
         
}
void translate()
{
    if(flag == 1)
    {
   xt+= 4;
   if(xt>1400)
        xt=0;
    }
    glutPostRedisplay();        
}

int main(int argc,char **argv)
{
    glutInit(&argc,argv);

    glutInitWindowSize(1400,800);
    glutInitWindowPosition(0,0);
    glutCreateWindow("Car animation ");

    glClearColor(1,1,1,1);
    gluOrtho2D(0,1400,0,800);

    glutDisplayFunc(disp);
    glutIdleFunc(translate);
   glutMouseFunc(mouse);

   glutMainLoop();
}