#include<GLUT/glut.h>
#include<OpenGL/gl.h>
#include<OpenGL/glu.h>
#include<string.h>

float ytranslate = -100;
int flag = 0;
void myInit()
{
    glClearColor(1,1,1,0);
    gluOrtho2D(-400,400,-300,300);
}
void mouse(int button,int state,int x,int y)
{
    if(state == GLUT_DOWN)
        flag = 1;
}
void draw()
{
    glClear(GL_COLOR_BUFFER_BIT );
    //brown
    glBegin(GL_POLYGON);
    glColor3f(0.3f,0.2f,0.2f);
    glVertex2f(-20,300);
    glVertex2f(-20,-300);
    glVertex2f(0,-300);
    glVertex2f(0,300);
    glEnd();

    int adj = 10;
    glBegin(GL_POLYGON);
    glColor3f(0.3f,0.2f,0.2f);
    glVertex2f(-200-adj,-300);
    glVertex2f(-200-adj,-250);
    glVertex2f(200-adj,-250);
    glVertex2f(200-adj,-300);
    glEnd();
    
    glBegin(GL_POLYGON);
    glColor3f(0.3f,0.2f,0.2f);
    glVertex2f(-100-adj,-250);
    glVertex2f(-100-adj,-200);
    glVertex2f(100-adj,-200);
    glVertex2f(100-adj,-250);
    glEnd();



if (flag == 1)
{
    //orange
    glBegin(GL_POLYGON);
    glColor3f(1.0f,0.5f,0.0f);

    glVertex2f(0,0+ytranslate);
    glVertex2f(0,50+ytranslate);
    glVertex2f(300,50+ytranslate);
    glVertex2f(300,0+ytranslate);

    glEnd();
    //white
    glColor3f(1.0f,1.0f,1.0f);
    glBegin(GL_POLYGON);
    
    
    glVertex2f(0,-50+ytranslate);
    glVertex2f(0,0+ytranslate);
    glVertex2f(300,0+ytranslate);
    glVertex2f(300,-50+ytranslate);

    glEnd();
    
//green
    glBegin(GL_POLYGON);
    glColor3f(0.0f,1.0f,0.0f);

    glVertex2f(0,-100+ytranslate);
    glVertex2f(0,-50+ytranslate);
    glVertex2f(300,-50+ytranslate);
    glVertex2f(300,-100+ytranslate);

    glEnd();

    
//centre blue
    glColor3f(0.0f,0.0f,1.0f);
    glEnable(GL_POINT_SMOOTH);
    glPointSize(20);
    glBegin(GL_POINTS);
    glVertex2f(150,-25 +ytranslate);
    glEnd();
   
    glPointSize(0.5);
    glColor3f(0,0,0);


//border
   glBegin(GL_LINES);
    glVertex2f(0,50+ytranslate);
    glVertex2f(300,50+ytranslate);
 
    glVertex2f(300,50+ytranslate);
    glVertex2f(300,-100 +ytranslate);

   glVertex2f(300,-100 +ytranslate);    
    glVertex2f(0,-100+ytranslate);
   glEnd(); 
    
   
   
}

    glutSwapBuffers();
}
void translate()
{
    if(flag == 1)
    if(ytranslate + 50 < 300  )
       ytranslate += 2;

    glutPostRedisplay();   
}
int main(int argc , char **argv)
{

    glutInit(&argc,argv);

    glutInitDisplayMode(GLUT_RGB );

    glutInitWindowPosition(0,0);
    glutInitWindowSize(600,800);

    glutCreateWindow("India Flag ");

    myInit();


    glutDisplayFunc(draw);
    glutIdleFunc(translate);
    glutMouseFunc(mouse);

    glutMainLoop();
}