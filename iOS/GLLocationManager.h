//
//  GLLocationManager.h
//  GeoLoqal
//
//  Created by user on 30/10/12.
//  Copyright (c) 2012 GeoLoqal Inc.. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "GLLocationManager.h"

typedef struct {
	double latitude;
	double longitude;
} GLLocationCoordinate2D;

typedef enum{
    Test_GL, //Default TestModeType
    Test_PROD,
} TestModeType;

typedef enum{
    CriteriaAll, 
    CriteriaAny,
} CheckCriteriaType;

typedef enum{
    LogMode_DEBUG, 
    LogMode_PROD,
} LogModeType;

@protocol GeoLoqalDelegate <NSObject>

@required
-(void)geoLoqalLocationLatitude :(double)lat longitude:(double)lon;

@optional

//// These are the delegate methods to get the respective GeoLoqal values////

///// Methods for testcases and testcase types /////
-(void)testCaseName :(NSMutableArray *)testCaseNames:(NSMutableArray *)testCaseType;
-(void)testcaseType :(NSString *)testcaseType;

///// Methods for triggers /////
-(void)triggerName :(NSMutableArray *)triggerNames; 
-(void)triggerStatus :(NSString *)triggerStatus;

/////// Methods for Group triggers ////////
-(void)triggerGroupName :(NSMutableArray *)groupNames; 
-(void)groupedTriggerStatus :(NSString *)triggerStatus;

/////////// GLLocationManager GeoCoding and Reverse GeoCoding Delegate Methods //////
-(void)glGeoCodeLocation:(id)location;
-(void)glReverseGeoCodePlace:(id)place;


//// Methods to get all test case groups ////
-(void)allTestcaseGroups :(NSMutableArray *)testcaseGroups; 

//// Method to get the list of layers ////
-(void)layersList :(NSMutableArray *)layers; 

//// Method to get the list of public layers ////
-(void)publicLayersList :(NSMutableArray *)publicLayers; 

//// Method to get the list of points inside a layers ////
-(void)layerPointsList :(NSMutableArray *)layerPoints;

///// Delegate methods for geoloqal get places API ///
-(void)geoLoqalGetPlaces :(id)places;

//for failure in Geocode response
-(void)didFailedWithGeoCodeError:(NSString*)error;

//for failure in ReverseGeocode response
-(void)didFailedWithReverseGeoCodeError:(NSString*)error;

//delegate for error in getting places
-(void)didFailedWithPlaceError:(NSString*)error;

@end

@interface GLLocationManager : NSObject

@property (nonatomic, strong) id<GeoLoqalDelegate> delegate;

@property (nonatomic) TestModeType testMode;

@property(nonatomic) double frequency; 

@property(nonatomic,assign)BOOL privacyFlag;

// Unit of test case of type Sequential Polyline 
@property(nonatomic,strong)NSString *unitOfSpeed;

@property(nonatomic,strong)NSString *referenceId;

///To display the URLs of web services in console ////
@property(nonatomic) LogModeType logMode; 

@property(nonatomic) double distanceFilter;

@property(nonatomic) double desiredAccuracy;

// Set API key which will get from http://dev.geoloqal.com/ for GeoLoqal SDK
+(void)setApiKey:(NSString *)geoloqalApiKey;

////////////multitasking
+(void)applicationDidEnterBackground;

+(void)applicationDidEnterForeground;

//Get all Testcases
-(void)getTestcases;

//Get all Testcase types
-(void)getTestcaseType:(NSString *)testcaseName;

// get GeoPoint latitude longitude for TestcaseTypes:- (By Polyline ,By Polygon,By Circle)
-(void)getGeoPoint:(NSString *)testCaseName;

//get latitude and longitude for TestcaseType:- (By Sequential Polyline)
-(void)getNextPoint:(NSString *)testCaseName;

//get latitude and longitude for TestcaseType:- (By Address)
-(void)getDirectionPoint:(NSString *)testCaseName speed:(double)speed;

// For Triggers //

// get all Trigger names
-(void)getTriggers;

// Method for checking trigger matching to a location for Test_GL mode
-(void)checkGeoTrigger:(NSString *)triggerName lat:(double)latitude lon:(double)longitude;

// Method for checking trigger matching to a location for Test_PROD mode
-(void)checkGeoTrigger:(NSString *)triggerName;
-(void)checkBatterySafeGeoTrigger:(NSString *)triggerName;
-(void)checkIPBasedGeoTrigger:(NSString *)triggerName;

// get all Trigger groups
-(void)getTriggerGroups;

// Method for checking  group trigger matching to a location for Test_GL mode
-(void)checkGroupTrigger:(NSString *)groupName lat:(double)latitude lng:(double)longitude checkCriteria:(CheckCriteriaType)checkCriteriaType;

// Method for checking  group trigger matching to a location for Test_PROD mode
-(void)checkGroupGeoTrigger:(NSString *)groupName checkCriteriaType:(CheckCriteriaType)criteriaType;
-(void)checkBatterySafeGroupGeoTrigger:(NSString *)groupName checkCriteriaType:(CheckCriteriaType)criteriaType;
-(void)checkIPBasedGroupGeoTrigger:(NSString *)groupName checkCriteriaType:(CheckCriteriaType)criteriaType;

//API call for get places
-(void)getPlaces:(double)latitude longitude:(double)longitude provider:(NSString *)provider radius:(double)radius query:(NSString*)queryString;

//To get all the testcase groups 
-(void)getAllTestcaseGroups;

//To get the list of layers
-(void)getLayersList;

//To get the list of public layers
-(void)getPublicLayers;

//To get the points inside a layer
-(void)getLayerPointsList :(NSString *)layerName;

//To get the address from latitude and longitude
-(void)reverseGeoCode:(double)latitude longitude:(double)longitude;

//To get the latiude and longitude of a place
-(void)geoCode:(NSString *)address;


@end
