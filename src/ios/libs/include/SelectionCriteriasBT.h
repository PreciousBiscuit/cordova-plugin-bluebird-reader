//
//  SelectionCriteriasBT.h
//  BlueBirdSDKiOS
//
//  Created by BluebirdCorp on 27/11/16.
//  Copyright © 2016-2017 Bluebirdcorp... All rights reserved.
//
//Date: 7/2/17
//update the full file as mentioned by Park
#import <Foundation/Foundation.h>
/**
 * SelectionCriterias's Criteria Minimum Count
 */    
#define CRITERIA_MIN_COUNT   1

/**
 * SelectionCriterias's Criteria Max Count
 */    
#define CRITERIA_MAX_COUNT   8

/**
 * SelectionCriterias's Criteria Mask Max Size
 */      
#define MASK_MAX_SIZE        64

//For a tag mask, RFID_18K6C_MEMORY_BANK_RESERVED is not a valid value.
/**
 * SelectionCriterias Memory Type
 */    
#define SCMemType_EPC    1
#define SCMemType_TID    2
#define SCMemType_USER   3

/* Match – Assert SL or inventoried -> A */ 
/* Non-Match – Deassert SL or inventoried -> B */ 
//    RFID_18K6C_ACTION_ASLINVA_DSLINVB, 
/* Match – Assert SL or inventoried -> A */ 
/* Non-Match – Nothing */ 
//    RFID_18K6C_ACTION_ASLINVA_NOTHING, 
/* Match – Nothing */ 
/* Non-Match – Deassert SL or inventoried -> B */ 
//    RFID_18K6C_ACTION_NOTHING_DSLINVB, 
/* Match – Negate SL or (A -> B, B -> A) */ 
/* Non-Match – Nothing */ 
//    RFID_18K6C_ACTION_NSLINVS_NOTHING, 
/* Match – Deassert SL or inventoried -> B */
/* Non-Match – Assert SL or inventoried -> A */ 
//    RFID_18K6C_ACTION_DSLINVB_ASLINVA,
/* Match – Deassert SL or inventoried -> B */ 
/* Non-Match – Nothing */
//    RFID_18K6C_ACTION_DSLINVB_NOTHING, 
/* Match – Nothing */ 
/* Non-Match – Assert SL or inventoried -> A */ 
//    RFID_18K6C_ACTION_NOTHING_ASLINVA, 
/* Match – Nothing */ 
/* Non-Match – Negate SL or (A -> B, B -> A) */ 
//    RFID_18K6C_ACTION_NOTHING_NSLINVS

/**
 * SelectionCriterias Action Type
 */    
/* Match – Assert SL or inventoried -> A */ 
/* Non-Match – Deassert SL or inventoried -> B */ 
#define SCActionType_ASLINVA_DSLINVB    0
/* Match – Assert SL or inventoried -> A */ 
/* Non-Match – Nothing */ 
#define SCActionType_ASLINVA_NOTHING    1
/* Match – Nothing */ 
/* Non-Match – Deassert SL or inventoried -> B */ 
#define SCActionType_NOTHING_DSLINVB    2
/* Match – Negate SL or (A -> B, B -> A) */ 
/* Non-Match – Nothing */ 
#define SCActionType_NSLINVS_NOTHING    3
/* Match – Deassert SL or inventoried -> B */
/* Non-Match – Assert SL or inventoried -> A */ 
#define SCActionType_DSLINVB_ASLINVA    4
/* Match – Deassert SL or inventoried -> B */ 
/* Non-Match – Nothing */
#define SCActionType_DSLINVB_NOTHING    5
/* Match – Nothing */ 
/* Non-Match – Assert SL or inventoried -> A */ 
#define SCActionType_NOTHING_ASLINVA    6
/* Match – Nothing */ 
/* Non-Match – Negate SL or (A -> B, B -> A) */ 
#define SCActionType_OTHING_NSLINVS    7

/**
 * SelectionCriterias Result
 */    
#define Result_MASK_LENGTH_BIT_ERROR   -6
#define Result_START_POS_ERROR   -5
#define Result_MASK_ERROR   -4
#define Result_ACTION_ERROR   -3
#define Result_MEMTYPE_ERROR   -2
#define Result_CRITERIA_COUNT_ERROR   -1
#define Result_SUCCESS   0

@interface SelectionCriteriasBT : NSObject
@property (nonatomic) NSMutableArray *mCriteriaList;
/**
     * makeCriteria for Selection API
	 * @param		scMemType			The memory bank type(EPC = 1, TID = 2, USER = 3)
	 * @param		mask				HEX form(ex. "3000", "1234ABFF")
	 * @param		selectStartPosByte	Position that start select is multiply twice value on byte unit
	 * @param		selectMaskLengthBit	Length of the selected mask(bit)
	 * @param		scActionType		Action type(0~7)
	 * @return      Success : Result.SUCCESS = 0 <BR/>List Error : Result.CRITERIA_COUNT_ERROR = -1 <BR/>scMemType Error : Result.MEMTYPE_ERROR = -2 <BR/>scActionType Error : Result.ACTION_ERROR = -3 <BR/>mask Error : Result.MASK_ERROR = -4 <BR/>start positiong Error : Result.START_POS_ERROR = -5 <BR/>mask length bit Error : Result.MASK_LENGTH_BIT_ERROR = -6
*/   
-(int)makeCriteria:(int)scMemType mask:(NSString *)mask selectStartPosByte:(int)selectStartPosByte selectMaskLengthBit:(int)selectMaskLengthBit scActionType:(int) scActionType;
/**
     * getCriteria value
	 * @return		NSMutableArray with criteria value
     */  
-(NSMutableArray*) getCriteria;
@end
