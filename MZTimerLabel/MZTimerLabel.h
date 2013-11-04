//
//  MZTimerLabel.h
//  Version 0.1
//  Created by MineS Chan on 2013-10-16
//

// This code is distributed under the terms and conditions of the MIT license. 

// Copyright (c) 2013 Matej Bukovinski
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.

#import <UIKit/UIKit.h>


/**********************************************
 MZTimerLabel Delegate method for finish of countdown timer
 @optional
    - timerLabelEndCountDownTimer:withTime:
**********************************************/
 
@class MZTimerLabel;
@protocol MZTimerLabelDelegate <NSObject>
@optional
-(void)timerLabelEndCountDownTimer:(MZTimerLabel*)timerLabel withTime:(NSTimeInterval)countTime;
@end


/**********************************************
 MZTimerLabel TimerType Enum
 **********************************************/
typedef enum{
    MZTimerLabelTypeStopWatch,
    MZTimerLabelTypeTimer
}MZTimerLabelType;

/**********************************************
 MZTimerLabel Class Defination
 **********************************************/

@interface MZTimerLabel : UILabel{
    
#if NS_BLOCKS_AVAILABLE
    void (^endedBlock)(NSTimeInterval);
#endif
    NSTimeInterval timeUserValue;
}

/*Delegate for finish of countdown timer */
@property (strong) id<MZTimerLabelDelegate> delegate;

/*Time format wish to display in label*/
@property (nonatomic,strong) NSString *timeFormat;

/*Target label obejct, default self if you do not initWithLabel nor set*/
@property (strong) UILabel *timeLabel;

/*Type to choose from stopwatch or timer*/
@property (assign) MZTimerLabelType timerType;

/*Current countdown/stopwatch time*/
@property (nonatomic,assign) NSTimeInterval timeValue;

/*is The Timer Running?*/
@property (assign) BOOL counting;

/*do you reset the Timer after countdown?*/
@property (assign) BOOL resetTimerAfterFinish;


/*--------Init method to choose*/
-(id)initWithTimerType:(MZTimerLabelType)theType;
-(id)initWithLabel:(UILabel*)theLabel andTimerType:(MZTimerLabelType)theType;
-(id)initWithLabel:(UILabel*)theLabel;


/*--------Timer control method to use*/
-(void)start;
#if NS_BLOCKS_AVAILABLE
-(void)startWithEndingBlock:(void(^)(NSTimeInterval countTime))end; //use it if you are not going to use delegate
#endif
-(void)pause;
-(void)reset;



@end

