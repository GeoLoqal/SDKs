<h1 style="text-align: left;" align="center">Geotargeting &amp; Geolocation iOS SDKs - by GeoLoqal</h1>
<strong> </strong>
<h2><strong>Getting started with the iOS SDK</strong></h2>
<h3>Sample App</h3>
The best way to get started is to download our sample app  and start making any necessary changes. After downloading the sample app, you'll get an application that integrates the GeoLoqal SDK, and you can begin modifying it as needed. It is also a good reference if you're adding the SDK to an existing app and need to see which specific build settings are required for linking to the library.

<h3>Set your Application API Key</h3>
The Sample iPhone app project will get you started quickly using the SDK. When you open the XCode project, all you need to set your Application API Key in <code>application:didFinishLaunchingWithOptions:</code> method, which you can get from our developer site.

<code>[GLLocationManager setApiKey: @”Your API Key”];</code>

After you build the project, you should see the sample app in the simulator.
<h2><strong>Adding the SDK to an Existing Project</strong></h2>
If you are adding the GeoLoqal SDK to an existing iPhone app, follow the steps below.

<h3>1) Add the library to your project</h3>
Copy the GeoLoqalSDK folder, including libGeoLoqal.a and the *.h files, to your project's folder.

Add <strong><em>–licucore</em></strong> to Other Linker Flags in your build setting.

<a href="http://geoloqal.com/wp-content/uploads/2012/11/AddiOSLibToProject.jpg"><img class=" wp-image-5032 alignnone" title="AddiOSLibToProject" alt="" src="http://geoloqal.com/wp-content/uploads/2012/11/AddiOSLibToProject-300x172.jpg" width="466" height="239" /></a>
<h3>2) Add the required frameworks to your project.</h3>
CoreLocation.framework
<h3>3) Set up your App Delegate</h3>
<ul>
 <li>Import the <code>“GLLocationManager.h”</code> .</li>
	<li>Set the Application API KEY inside your <code>application:didFinishLaunchingWithOptions:</code> method.</li>
</ul>
<pre>- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
// Sets your API Key
[GLLocationManager setAPIKey:@"Your API Key"];
// ...
}</pre>
<h2><strong>Handling Events</strong></h2>
If you want to be notified when certain events occur, then you have to implement GeoLoqalDelegate.

Then create an instance of <code>GLLocationManager</code>.
<pre>GLLocationManager  *_glLocationManager = [[GLLocationManager alloc] init];
_glLocationManager.delegate = self;</pre>
Set the speed property for getting the direction point of test case of <em>By Address</em> type.

Set the output type to the instance of GLLocationManager as <strong><em>json</em></strong> or <strong><em>xml</em></strong> in string format, which is a required property.
<pre>GLLocationManager  *_glLocationManager = [[GLLocationManager alloc] init];</pre>
<pre>_glLocationManager.outputType = @”json”;</pre>
<pre>_glLocationManager.speed = 40;</pre>
<pre>_glLocationManager.delegate = self;</pre>
<h3><strong>For Test Cases</strong></h3>
Call the <strong>getTestCaseNames</strong> method to get all the test cases and override a delegate method to get the array of test cases. Inside the delegate method call the <code>registrationWithApiKey:andTestCase:</code> for a particular test case.
<pre>[_glLocationManager getTestCaseNames];
-(void)testCaseName : (NSMutableArray *)testCasenames{
//In this method we get the array of testcases
}</pre>
After getting the list of test cases, call the registrationWithTestCase: for a particular test case.

According to the test case, it will check the type of test case internally and returns the point accordingly.

So we have to override the delegate method to get the latitude and longitude points.
<pre>-(void)geoPointLatitude : (double)lat longitude: (double)lon;
-(void)byAddressLatitude : (double)lat longitude: (double)lon;
-(void)bySequentialPolylineLatitude : (double)lat longitude: (double)lon;</pre>
<h2></h2>
<h2><strong>For Triggers</strong></h2>
Call the <strong>getTriggerNames</strong> method to get all the triggers and override a delegate method to get the array of triggers.
<pre>[_glLocationManager getTriggerNames];
-(void)triggerName : (NSMutableArray *)triggerNames {
//In this method we get the array of triggers
}</pre>
Call the <code>getCheckedGeoTrigger:lat:lon:</code> for a particular trigger to check whether the trigger matches the point on not. The output comes inside the delegate method triggerStatus:
<pre>[_glLocationManager getCheckedGeoTrigger:@”Trigger Name” lat:@”Latitude” lon:@”Longitude”];
-(void)triggerStatus : (NSString *)triggerStatus{
//The triggerStatus gives the check trigger status
}</pre>



<h1 style="text-align: left;">Geotargeting &amp; Geolocation android SDKs</h1>
<strong>
</strong>The Android SDK basically offer similar functionality as the GeoLoqal APIs (geolocation, geofencing). There are quite a few differences, however, mainly around intelligent user geo-targeting. The biggest impact is around enabling rich location analytics by using our SDKs.
<h2><strong>Getting Started with the Android SDK</strong></h2>
<h3>Sample App</h3>
The main objective of  <strong>GeoLoqal SDK</strong> is that it can easily provide users'  latitude and longitude while running your application in an android emulator.

The easiest way to get started is to download our sample app and start making any necessary changes.

&nbsp;

When you download the sample app, you'll get a fully-functional project that integrates the SDK, and you can begin modifying it as needed. It is also a good reference if you're adding the SDK to an existing app and need to see which specific build settings are required for linking to the library.

&nbsp;
<h2>Installation</h2>
The <strong>GeoLoqal Android SDK</strong> is distributed as a JAR library. Simply drop the .jar into your project's libs/ directory and you should be good to go.


For developers with access to the Geoloqal Android SDK source code, you can also reference the SDK as an Android Library Project.

After pulling down the source you can easily reference an Android Library project from Eclipse or from the command line.

If you're having trouble try checking your application's <code>project.properties</code> file.

&nbsp;
<h2>Adding the SDK to an Existing Project</h2>
If you are adding the <strong>GeoLoqal SDK</strong> to an existing <strong>Android</strong> <strong>app</strong>, follow the steps below.

&nbsp;
<h2>Add the jar to your project</h2>
Copy the <strong>GeoLoqalSDK</strong> jar file  to your project's lib folder. You can keep the jar file outside Eclipse, then configure it to build path to add the jar. Your project folder should look something like the following.

&nbsp;

<strong>Steps to add jar to build path.</strong>

<a href="http://geoloqal.com/wp-content/uploads/2012/11/AndroidAddJarToProject.jpg"><img class="alignnone size-full wp-image-5039" title="AndroidAddJarToProject" src="http://geoloqal.com/wp-content/uploads/2012/11/AndroidAddJarToProject.jpg" alt="" width="464" height="230" /></a>

&nbsp;

<a href="http://geoloqal.com/wp-content/uploads/2012/11/AndroidAddJarToProject-2.jpg"><img class="alignnone size-full wp-image-5038" title="AndroidAddJarToProject-2" src="http://geoloqal.com/wp-content/uploads/2012/11/AndroidAddJarToProject-2.jpg" alt="" width="469" height="246" /></a>

&nbsp;

<a href="http://geoloqal.com/wp-content/uploads/2012/11/AndroidAddJarToProject-3.jpg"><img class="alignnone size-full wp-image-5037" title="AndroidAddJarToProject-3" src="http://geoloqal.com/wp-content/uploads/2012/11/AndroidAddJarToProject-3.jpg" alt="" width="468" height="247" /></a>

&nbsp;
<h2>Set your Application API Key</h2>
The Sample Android app project will get you started quickly using the SDK. When you open the Eclipse  project, all you need to do is fill in your Application API Key in Global area, which you can get from our <em>developer site</em>. <strong>For security reasons, you should leave API Key as an empty string.</strong>
<h2>Usage</h2>
Before you begin, you'll need to modify your application's <code>AndroidManifest.xml</code> file to include the following permissions.
<pre>&lt;uses-permission android:name=<em>"android.permission.INTERNET"</em>/&gt;</pre>
<pre>&lt;uses-permission android:name=<em>"android.permission.ACCESS_FINE_LOCATION"</em>/&gt;</pre>
<pre>&lt;uses-permission android:name=<em>"android.permission.READ_PHONE_STATE"</em> /&gt;</pre>
<h2>Use the jar in your project</h2>
<ul>
 <li>Create the object of <strong>GLLocationManager</strong> class  as below.<strong></strong></li>
</ul>
<pre>GLLocationManager _locationManager= new GLLocationManager(this);</pre>
<ul>
	<li>SetApi key by calling method setApiKey() using GLLocationManager Object.</li>
</ul>
<pre>_locationManager.setApiKey(String apiKey);</pre>
<ul>
	<li>Set unit  by calling method setUnit() (kph/mph) using GLLocationManager Object.</li>
</ul>
<pre>_locationManager.setUnit(String unit);</pre>
<ul>
	<li>Set speed by calling method setSpeed() using GLLocationManager Object.</li>
</ul>
<pre>_locationManager.setApiKey(int speed);</pre>
&nbsp;

<strong>Handling Events</strong> <strong>for current location latitude and longitude</strong>
<ul>
	<li>Call <strong>getTestCases() </strong>method to get all <strong>testcases name</strong> list as below:</li>
</ul>
<pre>_ locationManager. getTestCases();</pre>
<ul>
	<li>Call <strong>registration ()</strong> by passing argument <strong>as  testcase name</strong> to get  <strong>GLLocation object </strong> as below.</li>
</ul>
<pre>GLLocation location= _ locationManager. registration(String testcase_name);</pre>
<ul>
	<li>Get current latitude and longitude using GLLocation object as bellow.</li>
</ul>
<pre>  double latitude = location.getLatitude();</pre>
<pre>  double longitude = location.getLongitude();</pre>
&nbsp;

<strong>For Trigger</strong>
<ul>
	<li>Call  <strong>getTriggers ()</strong> method to get  list of  <strong>trigger_name</strong> and  <strong>trigger_type</strong> as given below—</li>
</ul>
<pre><strong></strong>ArrayList&lt;TriggerData&gt; _allTiggerData=_ locationManager.getTriggers();</pre>
<ul>
	<li>Call  <strong>checkGeoTrigger(String trigger_name,latitude,longitude)</strong> to check  given latitude and longitude is inside the trigger or not. See below code-</li>
</ul>
<pre><strong></strong>String  status=_ locationManager. checkGeoTrigger(String trigger_name,latitude,longitude);</pre>

