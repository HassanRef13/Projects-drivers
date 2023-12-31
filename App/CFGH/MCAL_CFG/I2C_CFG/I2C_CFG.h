/*
 * I2C_CFG.h
 *
 * Created: 10/7/2023 11:13:28 AM
 *  Author: Hassan
 */
/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  <Write File Name>
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef I2C_CFG_H_
#define I2C_CFG_H_

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define START_ACK                0x08 // start has been sent#define REP_START_ACK            0x10 // repeated start#define SLAVE_ADD_AND_WR_ACK     0x18 // Master transmit ( slave address + Write request ) ACK#define SLAVE_ADD_AND_RD_ACK     0x40 // Master transmit ( slave address + Read request ) ACK#define WR_BYTE_ACK              0x28 // Master transmit data ACK#define RD_BYTE_WITH_NACK        0x50// Master received data with not ACK
#define RD_BYTE_WITH_ACK         0x58 // Master received data with not A
// #define RD_BYTE_WITH_NACK        0x58 // Master received data with not ACK
// #define RD_BYTE_WITH_ACK         0x50 //Master received data with ACK
#define SLAVE_ADD_RCVD_RD_REQ    0xA8 // means that slave address is received with write req#define SLAVE_ADD_RCVD_WR_REQ    0x60 // means that slave address is received with read req#define SLAVE_DATA_RECEIVED      0x80 // means that read byte req is received#define SLAVE_BYTE_TRANSMITTED   0xC0 // means that write byte req is received


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

 
#endif /* I2C_CFG_H_ */

/**********************************************************************************************************************
 *  END OF FILE: Std_Types.h
 *********************************************************************************************************************/
