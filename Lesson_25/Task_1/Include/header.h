#ifndef TASK_1_HEADER_H
#define TASK_1_HEADER_H

struct coordinates
{
    double X;
    double Y;
    double X_0;
    double Y_0;
};

void scalpel (coordinates XY);
void hemostat ();
void tweezers ();
void suture (coordinates XY);

#endif
