/*
 * result_format.c
 *
 *  Created on: Feb 21, 2024
 *      Author: Admin
 */

#include "result_format.h"
#include "string.h"
void UART_transfer(uint8_t *data,uint8_t length)
{
//{	uint16_t length = strlen((char*)data);
	HAL_UART_Transmit(&huart1,data,length,HAL_MAX_DELAY);
//	HAL_Delay(1000);

}
void Default_font()
{
	uint8_t widthDefsize_command[]={0x1D,0x21,0x00};
	uint8_t fontDefsize_command[]={0x1B,0x21,0x00};
	uint8_t length_widthDefsize = sizeof(widthDefsize_command);
	uint8_t length_fontDefsize = sizeof(fontDefsize_command);
	HAL_UART_Transmit(&huart1,&widthDefsize_command,length_widthDefsize,HAL_MAX_DELAY);
	HAL_UART_Transmit(&huart1,&fontDefsize_command,length_fontDefsize,HAL_MAX_DELAY);
	Bold_disable();


}
void Bold_enable()
{
	uint8_t boldcommand[]={0x1B,0x45,0x01};
	uint8_t length = sizeof(boldcommand);
	HAL_UART_Transmit(&huart1,&boldcommand,length,HAL_MAX_DELAY);
	HAL_Delay(1000);

}
void Bold_disable()
{
	uint8_t boldcommand[]={0x1B,0x45,0x00};
	uint8_t length = sizeof(boldcommand);
	HAL_UART_Transmit(&huart1,&boldcommand,length,HAL_MAX_DELAY);
	HAL_Delay(1000);

}
void Vaccum_test_result_title(uint8_t *data1,uint8_t *data2)
{
	uint8_t smallfont_command[]={0x1B,0x21,0x01};
	uint8_t widthInc_command[] = {0x1D,0x21,0x10};
	uint8_t length_smallfont = sizeof(smallfont_command);
	uint8_t length_widthInc = sizeof(widthInc_command);
	uint8_t main_title[] = "RAISE LAB EQUIPMENT\n\n";
	HAL_UART_Transmit(&huart1,&smallfont_command,length_smallfont,HAL_MAX_DELAY);
	HAL_UART_Transmit(&huart1,&widthInc_command,length_widthInc,HAL_MAX_DELAY);
	Bold_enable();
	UART_transfer(main_title,strlen(main_title));
	Default_font();
	uint8_t data[] = "Package Integrity Tester\n";
	UART_transfer(data,strlen(data));
	uint8_t Model[] = "Model: ";
	uint8_t sr_no[] = "sr.No.: ";
	UART_transfer(Model,strlen(Model));
	UART_transfer(data1,strlen(data1));
	UART_transfer(sr_no,strlen(sr_no));
	UART_transfer(data2,strlen(data2));


}
void Vaccum_test_result_subtitle(uint8_t *data)
{
	uint8_t smallfont_command[]={0x1B,0x21,0x01};
	uint8_t widthInc_command[] = {0x1D,0x21,0x10};
	uint8_t length_smallfont = sizeof(smallfont_command);
	uint8_t length_widthInc = sizeof(widthInc_command);
	HAL_UART_Transmit(&huart1,&smallfont_command,length_smallfont,HAL_MAX_DELAY);
	HAL_UART_Transmit(&huart1,&widthInc_command,length_widthInc,HAL_MAX_DELAY);
	Bold_enable();
	UART_transfer(data,strlen(data));
	HAL_Delay(1000);
	Default_font();
}

void Vaccum_test_result_report(uint8_t *data1,uint8_t *data2,uint8_t *data3,uint8_t *data4,uint8_t *data5,uint8_t *data6)
{
	uint8_t subtitle1[] = "\nTest Report:\n\n";
	Vaccum_test_result_subtitle(subtitle1);
	Default_font();
	uint8_t company_name[] = "Company Name: ";
	UART_transfer(company_name,strlen(company_name));
	UART_transfer(data1,strlen(data1));
	uint8_t location[] = "\nLocation: ";
	UART_transfer(location,strlen(location));
	UART_transfer(data2,strlen(data2));
	uint8_t test_date[] ="\Test Date          : ";
	UART_transfer(test_date,strlen(test_date));
	UART_transfer(data3,strlen(data3));
	uint8_t test_start_time[] ="\Test Start Time    : ";
	UART_transfer(test_start_time,strlen(test_start_time));
	UART_transfer(data4,strlen(data4));
	uint8_t test_end_time[] ="\Test End Time      : ";
	UART_transfer(test_end_time,strlen(test_end_time));
	UART_transfer(data5,strlen(data5));
	uint8_t user_name[] = "\nUser Name: ";
	UART_transfer(user_name,strlen(user_name));
	UART_transfer(data6,strlen(data6));


}
void User_prod_details(uint8_t *data2,uint8_t *data3,uint8_t *data4,uint8_t *data5,uint8_t *data6,uint8_t *data7,uint8_t *data8)
{
	uint8_t subtitle2[] = "\nProduct details:\n";
	Vaccum_test_result_subtitle(subtitle2);
	Default_font();
	uint8_t prod_name[] = "\nProd. Name: ";
	UART_transfer(prod_name,strlen(prod_name));
	UART_transfer(data2,strlen(data2));
	uint8_t prod_no[] ="\nProd. No.: ";
	UART_transfer(prod_no,strlen(prod_no));
	UART_transfer(data3,strlen(data3));
	uint8_t batch_no[] ="\nBatch No: ";
	UART_transfer(batch_no,strlen(batch_no));
	UART_transfer(data4,strlen(data4));
	uint8_t batch_size[] ="\nBatch Size: ";
	UART_transfer(batch_size,strlen(batch_size));
	UART_transfer(data5,strlen(data5));
	uint8_t sample_qty[] ="\nSample Qty: ";
	UART_transfer(sample_qty,strlen(sample_qty));
	UART_transfer(data6,strlen(data6));
	uint8_t package_type[] ="\nPackage type: ";
	UART_transfer(package_type,strlen(package_type));
	UART_transfer(data7,strlen(data7));
	uint8_t tolerance[] ="\nTolerance: ";
	UART_transfer(tolerance,strlen(tolerance));
	UART_transfer(data8,strlen(data8));


}
void Test_settings(uint8_t *data1,uint8_t *data2,uint8_t *data3,uint8_t *data4)
{
	uint8_t subtitle2[] = "\nTest Settings: \n";
	Vaccum_test_result_subtitle(subtitle2);
	Default_font();
	uint8_t set_vaccum[] = "\nSet Vaccum : ";
	UART_transfer(set_vaccum,strlen(set_vaccum));
	UART_transfer(data1,strlen(data1));
	uint8_t act_vaccum[] = "Act. Vaccum : ";
	UART_transfer(act_vaccum,strlen(act_vaccum));
	UART_transfer(data2,strlen(data2));
	uint8_t line1[]="+/- 10mmHg\n";
	UART_transfer(line1,strlen(line1));
	uint8_t set_pressure[] ="\Set Pressure : ";
	UART_transfer(set_pressure,strlen(set_pressure));
	UART_transfer(data3,strlen(data3));
	uint8_t act_pressure[] ="Act. Pressure";
	UART_transfer(act_pressure,strlen(act_pressure));
	UART_transfer(data4,strlen(data4));
	uint8_t line2[]="+/- 0.01333 bar\n";
	UART_transfer(line2,strlen(line2));

}
void Test_result(uint8_t data0,uint8_t *data1,uint8_t *data2,uint8_t *data3,uint8_t *data4,uint8_t *data5)
{

	uint8_t subtitle3[] = "\nTest Result: \n";
	Vaccum_test_result_subtitle(subtitle3);
	Default_font();
	uint8_t test_duration[] ="\nTest Duration: ";
	UART_transfer(test_duration,strlen(test_duration));
	UART_transfer(data0,strlen(data0));
	uint8_t test_sample_no[] ="\nTest Sample no.: ";
	UART_transfer(test_sample_no,strlen(test_sample_no));
	UART_transfer(data1,strlen(data1));
	uint8_t weight_before_test[] ="Weight Before Test(Mg): ";
	UART_transfer(weight_before_test,strlen(weight_before_test));
	UART_transfer(data2,strlen(data2));
	uint8_t weight_after_test[] ="Weight After Test(Mg): ";
	UART_transfer(weight_after_test,strlen(weight_after_test));
	UART_transfer(data3,strlen(data3));
	uint8_t difference[] ="Difference:  ";
	UART_transfer(difference,strlen(difference));
	UART_transfer(data4,strlen(data4));
	uint8_t test_result[] ="\nTest Result(Pass/Fail): ";
	UART_transfer(test_result,strlen(test_result));
	UART_transfer(data5,strlen(data5));



}
void Printred_on(uint8_t *data1,uint8_t *data2)
{
	uint8_t printed_on[] = "\nPrinted On :";
	UART_transfer(printed_on,strlen(printed_on));
	UART_transfer(data1,strlen(data1));
	UART_transfer(data2,strlen(data2));
	uint8_t end[] = "\* * * * * * * * * * * * * * * * \n";
	UART_transfer(end,strlen(end));


}
void Test_status(uint8_t *data1,uint8_t *data2,uint8_t *data3,uint8_t *data4)
{
	uint8_t test_status[] = "\nTest Status: ";
	UART_transfer(test_status,strlen(test_status));
	UART_transfer(data1,strlen(data1));
	uint8_t performed_by[] = "\nPerformed by : ";
	UART_transfer(performed_by,strlen(performed_by));
	UART_transfer(data2,strlen(data2));
	uint8_t verified_by[] = "\nVerified by : ";
	UART_transfer(verified_by,strlen(verified_by));
	UART_transfer(data3,strlen(data3));
	uint8_t sign[] ="\nSign:";
	UART_transfer(sign,strlen(sign));
	UART_transfer(data4,strlen(data4));


}
//void Vaccum_test_result_fun1(uint8_t *data1,uint8_t *data2)
//{
//	uint8_t data[] = "Package Integrity Tester\n";
//	UART_transfer(data,strlen(data));
//	uint8_t Model[] = "Model: ";
//	uint8_t sr_no[] = "sr.No.: ";
//	UART_transfer(Model,strlen(Model));
//	UART_transfer(data1,strlen(data1));
//	UART_transfer(sr_no,strlen(sr_no));
//	UART_transfer(data2,strlen(data2));
//
//}

// Validation Report functions

void Validation_report_start(uint8_t *data1,uint8_t *data2,uint8_t *data3,uint8_t *data4,uint8_t *data5 )
{
	uint8_t subtitle1[] = "\nValidation Report: \n";
	Vaccum_test_result_subtitle(subtitle1);
	uint8_t company_name[] = "\nCompany Name: ";
	UART_transfer(company_name,strlen(company_name));
	UART_transfer(data1,strlen(data1));
	uint8_t location[] = "Location: ";
	UART_transfer(location,strlen(location));
	UART_transfer(data2,strlen(data2));
	uint8_t test_date[] = "Test Date: ";
	UART_transfer(test_date,strlen(test_date));
	UART_transfer(data3,strlen(data3));
	uint8_t test_start_time[] = "Test start Time: ";
	UART_transfer(test_start_time,strlen(test_start_time));
	UART_transfer(data4,strlen(data4));
	uint8_t test_end_time[] = "Test end Time: ";
	UART_transfer(test_end_time,strlen(test_end_time));
	UART_transfer(data5,strlen(data5));
}

void Validation_report_product_details(uint8_t *data1,uint8_t *data2)
{
	uint8_t subtitle2[] = "\nProduct details: \n";
	Vaccum_test_result_subtitle(subtitle2);
	Default_font();
	uint8_t prod_name[] = "\nProd Name: ";
	UART_transfer(prod_name,strlen(prod_name));
	UART_transfer(data1,strlen(data1));
	uint8_t prod_no[] = "Prod No.: ";
	UART_transfer(prod_no,strlen(prod_no));
	UART_transfer(data2,strlen(data2));


}

void Validation_report_results(uint8_t *data1,uint8_t *data2,uint8_t *data3,uint8_t *data4,uint8_t *data5,uint8_t *data6)
{
	uint8_t subtitle3[] = "\nValidation Results: \n";
	Vaccum_test_result_subtitle(subtitle3);
	Default_font();
	uint8_t test_number[] = "\nTest Number: ";
	UART_transfer(test_number,strlen(test_number));
	UART_transfer(data1,strlen(data1));
	uint8_t input[] = "Input mmgh: ";
	UART_transfer(input,strlen(input));
	UART_transfer(data2,strlen(data2));
	uint8_t maintained[] ="maintained mmhg: ";
	UART_transfer(maintained,strlen(maintained));
	UART_transfer(data3,strlen(data3));
	uint8_t meter[] ="\Meter mmhg: ";
	UART_transfer(meter,strlen(meter));
	UART_transfer(data4,strlen(data4));
	uint8_t difference[] ="Diff(+/-): ";
	UART_transfer(difference,strlen(difference));
	UART_transfer(data5,strlen(data5));
	uint8_t results[] ="\nResults(pass/fail): ";
	UART_transfer(results,strlen(results));
	UART_transfer(data6,strlen(data6));

}
void Validation_report_end(uint8_t *data1,uint8_t *data2,uint8_t *data3)
{
	uint8_t performed_by[] = "\nPerformed by : ";
	UART_transfer(performed_by,strlen(performed_by));
	UART_transfer(data1,strlen(data1));
	uint8_t verified_by[] = "\nVerified by : ";
	UART_transfer(verified_by,strlen(verified_by));
	UART_transfer(data2,strlen(data2));
	uint8_t sign[] ="\nSign:";
	UART_transfer(sign,strlen(sign));
	UART_transfer(data3,strlen(data3));

}



