/*
 * File:   main line follower.c
 * Author: Ing. Oscar Rigoberto Carvajal Ortiz
 *
 * Created on 28 de agosto de 2017, 11:25 AM
 */


#include <xc.h>
#include "funciones.h"
#include "lcd.h"
#include "config.h"
#include "cny70.h"
#include "Retardos.h"



void main(void) {
    int sensed;
    mcu_init();
    while (1) {       
        RobotControl();
        Pause_seg(1);
    }

    return;
}
