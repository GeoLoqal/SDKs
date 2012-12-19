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

// give speed for GeoLoqal SDK
@property(nonatomic)double speed;

// This is a mandatory property and the value is either json or xml
@property(nonatomic,strong)NSString *outputType;

// Sequential Polyline unit
@property(nonatomic,strong)NSString *unit;

// setting apikey from http://dev.geoloqal.com/ for GeoLoqal SDK
+(void)setApiKey:(NSString *)geoloqalApiKey;

// Register to GeoLoqal SDK for ios with an api key 
-(void)registrationWithTestCase:(NSString *)testCaseName;

// get all TestCaseNames for GeoLoqal SDK
-(void)getTestCaseNames;

// For Triggers //

// get all Trigger names
-(void)getTriggerNames;

//method for checking  whether latitude and loangitude points reside inside a particular Trigger
-(void)getCheckedGeoTriggerName:(NSString *)triggerName lat:(NSString *)latitude lon:(NSString *)longitude;


@end
