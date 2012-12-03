//
//  GLLocationManager.h
//  GeoLoqal
//
//  Created by user on 30/10/12.
//  Copyright (c) 2012 GeoLoqal LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "GeoLoqal.h"
#import <CoreLocation/CoreLocation.h>
#import "GLLocationManager.h"

@protocol GeoLoqalDelegate <NSObject>
@optional
-(void)geoPointLatitude :(double)lat longitude:(double)lon;
-(void)testCaseName :(NSMutableArray *)testCasenames;
-(void)triggerName :(NSMutableArray *)triggerNames;
-(void)triggerStatus :(NSString *)triggerStatus;
-(void)byAddressLatitude :(double)lat longitude:(double)lon;
-(void)bySequentialPolylineLatitude :(double)lat longitude:(double)lon;
-(void)createTriggerStatus :(NSString *)triggerStatus;

@end

@interface GLLocationManager : NSObject<CLLocationManagerDelegate>
@property (nonatomic, strong) id<GeoLoqalDelegate> delegate;
@property(nonatomic)double speed;
@property(nonatomic)int frequency;

-(id)initWithLatLon :(double)latitude :(double)longitude;
-(GLLocationCoordinate2D)registrationWithApiKey:(NSString *)apiKey andTestCase:(NSString *)testCaseName;
+(void)setApiKey:(NSString *)geoloqalApiKey;
-(NSMutableArray *)getTestCaseNames;
-(GLLocationCoordinate2D)getPoints;
-(GLLocationCoordinate2D)getNextPoints:(NSString *)testCaseName;
-(GLLocationCoordinate2D)getDirectionPoints:(NSString *)testCaseName;
-(NSString *)getTestTypes;
-(NSString *)getTestTypes :(NSString *)_testType;

-(NSMutableArray *)getTriggerNames;
-(NSString *)getCheckedGeoTrigger:(NSString *)triggerName lat:(NSString *)latitude lon:(NSString *)longitude;
-(NSString *)createInsideCircleTrigger:(NSString *)triggerName lat:(NSString *)latitude lon:(NSString *)longitude rad:(int)_radius;

-(void)timeIntervalCallOfDirection;
-(void)timeIntervalCallOfNextpoint;
@end
