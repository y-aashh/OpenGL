#include<stdlib.h>
#include<GLUT/glut.h>


static GLfloat theta = 0.0f;
float yt = -3;

void polygon()
{
            glBegin(GL_POLYGON);
            glColor3f(1.0f,0.0f,0.0f);//r
            glVertex3i(0,0,0);
            glVertex3i(1,0,0);
            glVertex3i(1,1,0);
            glVertex3i(0,1,0);
            glEnd();

            glBegin(GL_POLYGON);
            glColor3f(0.0f,1.0f,0.0f);//g
            glVertex3i(0,0,1);
            glVertex3i(1,0,1);
            glVertex3i(1,1,1);
            glVertex3i(0,1,1);
            glEnd();

            glBegin(GL_POLYGON);
            glColor3f(0.0f,0.0f,1.0f);//b
            glVertex3i(0,0,1);
            glVertex3i(0,1,1);
            glVertex3i(0,1,0);
            glVertex3i(0,0,0);
            glEnd();

            glBegin(GL_POLYGON);
            glColor3f(1.0f,1.0f,0.0f);//rg
            glVertex3i(0,1,1);
            glVertex3i(0,1,0);
            glVertex3i(1,1,0);
            glVertex3i(1,1,1);
            glEnd();

            glBegin(GL_POLYGON);
            glColor3f(1.0f,0.0f,1.0f);//rb
            glVertex3i(1,1,1);
            glVertex3i(1,1,0);
            glVertex3i(1,0,0);
            glVertex3i(1,0,1);
            glEnd();

            glBegin(GL_POLYGON);
            glColor3f(0.0f,1.0f,1.0f);//gb
            glVertex3i(1,0,1);
            glVertex3i(1,0,0);
            glVertex3i(0,0,0);
            glVertex3i(0,0,1);
            glEnd();

            glLineWidth(10);
            glBegin(GL_LINES);
            glColor3f(1,1,1);
            glVertex3f(-5,0.5,0.5);
            glVertex3f(6,0.5,0.5);
            glEnd();

            

}

void translate()
{
  theta+=4.0;
    if(theta>360.0)
        theta-=360.0;

   if(yt<3)
        yt+=0.025;
    else
    {
            yt = -3;
    }


       glutPostRedisplay();     
}








void display(void)
{
            glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
     
  glLoadIdentity();
  
    
  
  glRotatef(theta,1.0,0.0,0.0);
  glRotatef(0,0.0,1.0,0.0);
  glRotatef(20,0.0,0.0,1.0);
  
  glTranslatef(-0.5f+yt,-0.5f,-0.5f);

     
   polygon();
   
   glutSwapBuffers();
}





void myInit()
{
   glMatrixMode(GL_PROJECTION);
   glOrtho(-2.0,2.0,-2.0,2.0,-2.0,2.0);
   glMatrixMode(GL_MODELVIEW);
}




int main(int argc,char** argv)
{
            glutInit(&argc,argv);
            glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);
            glutInitWindowSize(1000,1000);
            glutCreateWindow("CUBE");
            myInit();
            glutDisplayFunc(display);
	          glutIdleFunc(translate);

            glEnable(GL_DEPTH_TEST);
            glutMainLoop();
            return 0;
}






























































































