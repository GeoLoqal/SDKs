

===========

GeoLoqal iOS SDK
===========


The Sample iPhone app project will get you started quickly using the GeoLoqal iOS SDK. When you open the XCode project, all you need to do is fill in your API key in the application:didFinishLaunchingWithOptions: which you can get from our developer site. 
 
After you build the project, you should see the sample app in the simulator.

 
When you click on the TestCases button, you will get all the test cases for the API key, Choose one of the test cases and press the Start Test button which will make an API request to the Geoloqal API and retrieve the latitude and longitude and displayed on the map.


When you click on the GeoTargeting button it retrieves all the triggers. By selecting one trigger we can check out the trigger matching for a latitude and longitude.

Adding the SDK to an Existing Project

If you are adding the GeoLoqal SDK to an existing iPhone app, follow the steps in documentation guide.

1) Add the library to your project

2) Add –licucore to Other Linker Flags in your build setting.

3) Add the required frameworks to your project.

4) Set up your App Delegate

5) Handle the Events for test cases and triggers
