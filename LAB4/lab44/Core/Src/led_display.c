/*
 * led_display.c
 *
 *  Created on: Sep 30, 2024
 *      Author: User
 */
#include "input_reading.h"
#include "main.h"
#include "input_processing.h"
#include "led_display.h"
int count=0,cnt=0;

// function blink led
void led_red_blink(){
	HAL_GPIO_TogglePin(red1_GPIO_Port, red1_Pin);
	HAL_GPIO_TogglePin(red2_GPIO_Port, red2_Pin);
}
void led_green_blink(){
	HAL_GPIO_TogglePin(green1_GPIO_Port, green1_Pin);
	HAL_GPIO_TogglePin(green2_GPIO_Port, green2_Pin);
}
void led_yellow_blink(){
	HAL_GPIO_TogglePin(yellow1_GPIO_Port, yellow1_Pin);
	HAL_GPIO_TogglePin(yellow2_GPIO_Port, yellow2_Pin);
}

// function turn off led
void off_red_led(){
	HAL_GPIO_WritePin(GPIOB, red1_Pin, 0);
	HAL_GPIO_WritePin(GPIOB, red2_Pin, 0);

}
void off_yellow_led(){
	HAL_GPIO_WritePin(GPIOB, yellow1_Pin, 0);
	HAL_GPIO_WritePin(GPIOB, yellow2_Pin, 0);

}
void off_green_led(){
	HAL_GPIO_WritePin(GPIOB, green1_Pin, 0);
	HAL_GPIO_WritePin(GPIOB, green2_Pin, 0);

}

void modify_red_duration()
{
	off_yellow_led();
	off_green_led();

	led_red_blink();
}
void modify_yellow_duration()
{
	off_red_led();
	off_green_led();

	led_yellow_blink();
}
void modify_green_duration()
{
	off_red_led();
	off_yellow_led();

	led_green_blink();
}

void turn_green1(){
	off_red_led();
	off_green_led();
	HAL_GPIO_WritePin(green1_GPIO_Port, green1_Pin, SET);
	HAL_GPIO_WritePin(red2_GPIO_Port, red2_Pin, SET);
}

void turn_red1(){
	off_green_led();
	HAL_GPIO_WritePin(red1_GPIO_Port, red1_Pin, SET);
	HAL_GPIO_WritePin(green2_GPIO_Port, green2_Pin, SET);
}
void display1(int num){
	switch (num){
	case 0:
		HAL_GPIO_WritePin(SEG_0_GPIO_Port, SEG_0_Pin, 0);
		HAL_GPIO_WritePin(SEG_1_GPIO_Port, SEG_1_Pin, 0);
		HAL_GPIO_WritePin(SEG_2_GPIO_Port, SEG_2_Pin, 0);
		HAL_GPIO_WritePin(SEG_3_GPIO_Port, SEG_3_Pin, 0);
		HAL_GPIO_WritePin(SEG_4_GPIO_Port, SEG_4_Pin, 0);
		HAL_GPIO_WritePin(SEG_5_GPIO_Port, SEG_5_Pin, 0);
		HAL_GPIO_WritePin(SEG_6_GPIO_Port, SEG_6_Pin, 1);
		break;
	case 1:
		HAL_GPIO_WritePin(SEG_0_GPIO_Port, SEG_0_Pin, 1);
		HAL_GPIO_WritePin(SEG_3_GPIO_Port, SEG_3_Pin, 1);
		HAL_GPIO_WritePin(SEG_4_GPIO_Port, SEG_4_Pin, 1);
		HAL_GPIO_WritePin(SEG_5_GPIO_Port, SEG_5_Pin, 1);
		HAL_GPIO_WritePin(SEG_6_GPIO_Port, SEG_6_Pin, 1);
		HAL_GPIO_WritePin(SEG_1_GPIO_Port, SEG_1_Pin, 0);
		HAL_GPIO_WritePin(SEG_2_GPIO_Port, SEG_2_Pin, 0);
			break;
	case 2:
		HAL_GPIO_WritePin(SEG_0_GPIO_Port, SEG_0_Pin, 0);
		HAL_GPIO_WritePin(SEG_1_GPIO_Port, SEG_1_Pin, 0);
		HAL_GPIO_WritePin(SEG_2_GPIO_Port, SEG_2_Pin, 1);
		HAL_GPIO_WritePin(SEG_3_GPIO_Port, SEG_3_Pin, 0);
		HAL_GPIO_WritePin(SEG_4_GPIO_Port, SEG_4_Pin, 0);
		HAL_GPIO_WritePin(SEG_5_GPIO_Port, SEG_5_Pin, 1);
		HAL_GPIO_WritePin(SEG_6_GPIO_Port, SEG_6_Pin, 0);
			break;
	case 3:
		HAL_GPIO_WritePin(SEG_0_GPIO_Port, SEG_0_Pin, 0);
		HAL_GPIO_WritePin(SEG_1_GPIO_Port, SEG_1_Pin, 0);
		HAL_GPIO_WritePin(SEG_2_GPIO_Port, SEG_2_Pin, 0);
		HAL_GPIO_WritePin(SEG_3_GPIO_Port, SEG_3_Pin, 0);
		HAL_GPIO_WritePin(SEG_4_GPIO_Port, SEG_4_Pin, 1);
		HAL_GPIO_WritePin(SEG_5_GPIO_Port, SEG_5_Pin, 1);
		HAL_GPIO_WritePin(SEG_6_GPIO_Port, SEG_6_Pin, 0);
			break;
	case 4:
		HAL_GPIO_WritePin(SEG_0_GPIO_Port, SEG_0_Pin, 1);
		HAL_GPIO_WritePin(SEG_1_GPIO_Port, SEG_1_Pin, 0);
		HAL_GPIO_WritePin(SEG_2_GPIO_Port, SEG_2_Pin, 0);
		HAL_GPIO_WritePin(SEG_3_GPIO_Port, SEG_3_Pin, 1);
		HAL_GPIO_WritePin(SEG_4_GPIO_Port, SEG_4_Pin, 1);
		HAL_GPIO_WritePin(SEG_5_GPIO_Port, SEG_5_Pin, 0);
		HAL_GPIO_WritePin(SEG_6_GPIO_Port, SEG_6_Pin, 0);
			break;
	case 5:
		HAL_GPIO_WritePin(SEG_0_GPIO_Port, SEG_0_Pin, 0);
		HAL_GPIO_WritePin(SEG_1_GPIO_Port, SEG_1_Pin, 1);
		HAL_GPIO_WritePin(SEG_2_GPIO_Port, SEG_2_Pin, 0);
		HAL_GPIO_WritePin(SEG_3_GPIO_Port, SEG_3_Pin, 0);
		HAL_GPIO_WritePin(SEG_4_GPIO_Port, SEG_4_Pin, 1);
		HAL_GPIO_WritePin(SEG_5_GPIO_Port, SEG_5_Pin, 0);
		HAL_GPIO_WritePin(SEG_6_GPIO_Port, SEG_6_Pin, 0);
			break;
	case 6:
		HAL_GPIO_WritePin(SEG_0_GPIO_Port, SEG_0_Pin, 0);
		HAL_GPIO_WritePin(SEG_1_GPIO_Port, SEG_1_Pin, 1);
		HAL_GPIO_WritePin(SEG_2_GPIO_Port, SEG_2_Pin, 0);
		HAL_GPIO_WritePin(SEG_3_GPIO_Port, SEG_3_Pin, 0);
		HAL_GPIO_WritePin(SEG_4_GPIO_Port, SEG_4_Pin, 0);
		HAL_GPIO_WritePin(SEG_5_GPIO_Port, SEG_5_Pin, 0);
		HAL_GPIO_WritePin(SEG_6_GPIO_Port, SEG_6_Pin, 0);
			break;
	case 7:
		HAL_GPIO_WritePin(SEG_0_GPIO_Port, SEG_0_Pin, 0);
		HAL_GPIO_WritePin(SEG_1_GPIO_Port, SEG_1_Pin, 0);
		HAL_GPIO_WritePin(SEG_2_GPIO_Port, SEG_2_Pin, 0);
		HAL_GPIO_WritePin(SEG_3_GPIO_Port, SEG_3_Pin, 1);
		HAL_GPIO_WritePin(SEG_4_GPIO_Port, SEG_4_Pin, 1);
		HAL_GPIO_WritePin(SEG_5_GPIO_Port, SEG_5_Pin, 1);
		HAL_GPIO_WritePin(SEG_6_GPIO_Port, SEG_6_Pin, 1);
			break;
	case 8:
		HAL_GPIO_WritePin(SEG_0_GPIO_Port, SEG_0_Pin, 0);
		HAL_GPIO_WritePin(SEG_1_GPIO_Port, SEG_1_Pin, 0);
		HAL_GPIO_WritePin(SEG_2_GPIO_Port, SEG_2_Pin, 0);
		HAL_GPIO_WritePin(SEG_3_GPIO_Port, SEG_3_Pin, 0);
		HAL_GPIO_WritePin(SEG_4_GPIO_Port, SEG_4_Pin, 0);
		HAL_GPIO_WritePin(SEG_5_GPIO_Port, SEG_5_Pin, 0);
		HAL_GPIO_WritePin(SEG_6_GPIO_Port, SEG_6_Pin, 0);
			break;
	case 9:
		HAL_GPIO_WritePin(SEG_0_GPIO_Port, SEG_0_Pin, 0);
		HAL_GPIO_WritePin(SEG_1_GPIO_Port, SEG_1_Pin, 0);
		HAL_GPIO_WritePin(SEG_2_GPIO_Port, SEG_2_Pin, 0);
		HAL_GPIO_WritePin(SEG_3_GPIO_Port, SEG_3_Pin, 0);
		HAL_GPIO_WritePin(SEG_4_GPIO_Port, SEG_4_Pin, 1);
		HAL_GPIO_WritePin(SEG_5_GPIO_Port, SEG_5_Pin, 0);
		HAL_GPIO_WritePin(SEG_6_GPIO_Port, SEG_6_Pin, 0);
			break;
	default:
		break;
	}
}

int digit_index=0;
const uint16_t digit_pins_1[] = {EN1_Pin, EN3_Pin};
const uint16_t digit_pins_2[] = { EN2_Pin, EN4_Pin};

uint8_t digit1, digit2,digit3,digit4 ;
int mode=1;

void display2number(int num1,int num2){
    digit1 = num1 / 10;
    digit2 = num1 % 10;
    digit3 = num2 / 10;
    digit4 = num2 % 10;
    if (num1 < 10) digit1 = 0;
    if (num2 < 10) digit3 = 0;

	HAL_GPIO_WritePin(GPIOB, EN1_Pin|EN2_Pin|EN3_Pin|EN4_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, mode_Pin, 0);

    switch (digit_index){
    case 0:
    	HAL_GPIO_WritePin(GPIOB, mode_Pin, 1);
    	display1(mode);
    	break;
    case 1:
		HAL_GPIO_WritePin(GPIOB, EN2_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOB, EN1_Pin, GPIO_PIN_SET);
		display1(digit1);
    	break;
    case 2:
		HAL_GPIO_WritePin(GPIOB, EN1_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOB, EN2_Pin, GPIO_PIN_SET);
		display1(digit2);
        	break;
    case 3:
		HAL_GPIO_WritePin(GPIOB, EN4_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOB, EN3_Pin, GPIO_PIN_SET);
		display1(digit3);
        	break;
    case 4:
		HAL_GPIO_WritePin(GPIOB, EN3_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOB, EN4_Pin, GPIO_PIN_SET);
		display1(digit4);
        	break;
    default:
        	break;
    }
    digit_index++;
	if (digit_index >4) digit_index=0;
}
void updatemode(int modee){
	mode=modee;
}

int num11,num22;

int cntred = 5, 	cntye = 3, 	cntgr = 5;
int cntred2 = 5, 	cntye2 = 3, cntgr2 = 5;

int red_duration = 5;
int yellow_duration = 3;
int green_duration = 5;

int new_red_duration = 0;
int new_yellow_duration = 0;
int new_green_duration = 0;

void timeledlight(){
	display2number(num11, num22);
}
void normalstate(){
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10 | GPIO_PIN_13 | GPIO_PIN_11 | GPIO_PIN_14, GPIO_PIN_RESET);

	if (cntred >= 0) {
		HAL_GPIO_WritePin(GPIOB, red2_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOB, yellow2_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOB, green2_Pin, GPIO_PIN_RESET);
		num11=cntred--;
	}
	else if (cntgr >= 0)  	{
		HAL_GPIO_WritePin(GPIOB, green2_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOB, red2_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOB, yellow2_Pin, GPIO_PIN_RESET);
		num11=cntgr--;
	}
	else if (cntye >= 0) 	{

		HAL_GPIO_WritePin(GPIOB, yellow2_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOB, red2_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOB, green2_Pin, GPIO_PIN_RESET);
		num11=cntye--;
	}

	if (cntgr2 >= 0)  	{

		HAL_GPIO_WritePin(GPIOB, green1_Pin, GPIO_PIN_SET);  // Bật đèn xanh
		HAL_GPIO_WritePin(GPIOB, red1_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOB, yellow1_Pin, GPIO_PIN_RESET);
		num22=cntgr2--;
	}
	else if (cntye2 >= 0) 	{

		HAL_GPIO_WritePin(GPIOB, yellow1_Pin, GPIO_PIN_SET); // Bật đèn vàng
		HAL_GPIO_WritePin(GPIOB, red1_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOB, green1_Pin, GPIO_PIN_RESET);
		num22=cntye2--;
	}
	else if (cntred2 >= 0) 	{

		HAL_GPIO_WritePin(GPIOB, red1_Pin, GPIO_PIN_SET);   // Bật đèn đ�?
		HAL_GPIO_WritePin(GPIOB, yellow1_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOB, green1_Pin, GPIO_PIN_RESET);
		num22=cntred2--;
	}

	if (cntred2 < 0 && cntgr2 < 0 && cntye2 < 0) {
		cntred2 = red_duration;
		cntgr2 = red_duration- yellow_duration ;
		cntye2 = yellow_duration;
	}

	if (cntred < 0 && cntgr < 0 && cntye < 0) {
		cntred = red_duration;
		cntgr = red_duration- yellow_duration;
		cntye = yellow_duration;
	}
}

void update_numbers(int duration) {
    num11 = duration;
    num22 = duration;
}
void increment_duration(int *new_duration) {
    *new_duration += 1;
    if (*new_duration > 99) {
        *new_duration = 1;
    }
    num11 = *new_duration;
    num22 = *new_duration;
}

void save_duration(int *new_duration, int *active_duration) {
    if (*new_duration > 0) {
        *active_duration = *new_duration;
        *new_duration = 0;
        update_numbers(*active_duration);
    }
}
// Button 2
void but2_red(){ increment_duration(&new_red_duration);}
void but2_ye() { increment_duration(&new_yellow_duration);}
void but2_gr() { increment_duration(&new_green_duration);}

// Button 3
void but3_red(){save_duration(&new_red_duration,  	&red_duration);}
void but3_ye() {save_duration(&new_yellow_duration, &yellow_duration);}
void but3_gr() {save_duration(&new_green_duration, 	&green_duration);}



