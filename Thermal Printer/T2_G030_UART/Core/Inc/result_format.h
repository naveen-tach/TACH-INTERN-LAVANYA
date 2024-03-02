/*
 * result_format.h
 *
 *  Created on: Feb 21, 2024
 *      Author: Admin
 */

#ifndef INC_RESULT_FORMAT_H_
#define INC_RESULT_FORMAT_H_
#include "main.h"
extern UART_HandleTypeDef huart1;

//Vaccum Test result report functions

void UART_transfer(uint8_t *data,uint8_t length);
void Bold_enable();
void Bold_disable();
void Vaccum_test_result_title(uint8_t *data1,uint8_t *data2);
void Vaccum_test_result_subtitle(uint8_t *data);
void Default_font();
//void Vaccum_test_result_fun1(uint8_t *data1,uint8_t *data2);
void Vaccum_test_result_report(uint8_t *data1,uint8_t *data2,uint8_t *data3,uint8_t *data4,uint8_t *data5,uint8_t *data6);
void User_prod_details(uint8_t *data2,uint8_t *data3,uint8_t *data4,uint8_t *data5,uint8_t *data6,uint8_t *data7,uint8_t *data8);
void Test_result(uint8_t data0,uint8_t *data1,uint8_t *data2,uint8_t *data3,uint8_t *data4,uint8_t *data);
void Printed_on(uint8_t *data1,uint8_t *data2);
void Test_status(uint8_t *data1,uint8_t *data2,uint8_t *data3,uint8_t *data4);
void Test_settings(uint8_t *data1,uint8_t *data2,uint8_t *data3,uint8_t *data4);

//Validation Report Functions

void Validation_report_start(uint8_t *data1,uint8_t *data2,uint8_t *data3,uint8_t *data4,uint8_t *data5 );
void Validation_report_product_details(uint8_t *data1,uint8_t *data2);
void Validation_report_results(uint8_t *data1,uint8_t *data2,uint8_t *data3,uint8_t *data4,uint8_t *data5,uint8_t *data6);
void Validation_report_end();
#endif /* INC_RESULT_FORMAT_H_ */
