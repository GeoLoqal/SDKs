//
//  GLLocationManager.h
//  GeoLoqal
//
//  Created by user on 30/10/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "GLLocationManager.h"

typedef struct {
	double latitude;
	double longitude;
} GLLocationCoordinate2D;

@protocol GeoLoqalDelegate <NSObject>

@required
-(void)geoLoqalPointLatitude :(double)lat longitude:(double)lon;

@optional

-(void)testCaseName :(NSMutableArray *)testCasenames;
-(void)createTriggerStatus :(NSString *)triggerStatus;
-(void)triggerName :(NSMutableArray *)triggerNames; 
-(void)triggerStatus :(NSString *)triggerStatus;

@end

@interface GLLocationManager : NSObject

@property (nonatomic, strong) id<GeoLoqalDelegate> delegate;

@property(nonatomic)double speed;

// This is a mandatory property and the value is either json or xml
@property(nonatomic,strong)NSString *outputType;

// Unit of test case of type Sequential Polyline 
@property(nonatomic,strong)NSString *unit;

// Set API key which will get from http://dev.geoloqal.com/ for GeoLoqal SDK
+(void)setApiKey:(NSString *)geoloqalApiKey;

// Register with GeoLoqal with a test case
-(void)registrationWithTestCase:(NSString *)testCaseName;

// Get all TestCaseNames for GeoLoqal 
-(void)getTestCaseNames;

// For Triggers //

// get all Trigger names
-(void)getTriggerNames;

// Method for checking  trigger matching to a location
-(void)getCheckedGeoTriggerName:(NSString *)triggerName lat:(NSString *)latitude lon:(NSString *)longitude;

// create a Trigger for "Inside_Circle" trigger type
-(void)createInsideCircleTrigger:(NSString *)triggerName lat:(NSString *)latitude lon:(NSString *)longitude rad:(int)_radius;

@end
