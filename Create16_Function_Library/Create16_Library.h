#include <stdio.h>
#include <kipr/botball.h>

void create_turn(int angle, int dir) {
    double turn_time = angle*18.125;
    int speed = 100 * dir;
    create_spin_CW(speed);
    msleep(turn_time);
    create_stop();
}

void create_drive_distance(int speed, double target_distance) {
    int current_distance = 0;

    if(target_distance<=50)
        target_distance*=1.1424; // 1.12
    else if(target_distance<=100)
        target_distance*=1.1688; // 1.1459
    else if(target_distance<=150)
        target_distance*=1.1867; // 1.1634
    else if(target_distance<=200)
        target_distance*=1.1863; // 1.163
    else
        target_distance*=1.2059; // 1.1823
    
    set_create_distance(0);
    while(current_distance < target_distance) {
        create_drive_straight(speed);
        msleep(10);
        current_distance = get_create_distance();
    }
    
    create_stop();
}

void lower_claw(int position) {

    

}

void raise_claw(int position) {



}
