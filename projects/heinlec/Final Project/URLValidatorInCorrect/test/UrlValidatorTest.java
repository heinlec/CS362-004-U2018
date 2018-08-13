/*Jason Long - ONID longjaso
Clarence (Cole) Palmer - ONID palmercl
Casey Heinle - ONID heinlec
*/


import junit.framework.TestCase;

//You can use this as a skeleton for your 3 different test approach
//It is an optional to use this file, you can generate your own test file(s) to test the target function!
// Again, it is up to you to use this file or not!

public class UrlValidatorTest extends TestCase {

   public UrlValidatorTest(String testName) {
      super(testName);
   }
   
   public void testManualTest()
   {
       UrlValidator thing = new UrlValidator();
       
       //String url = new String("htt://www.google.com/");
       //String url = new String("https://www.google.com");
       //String url = new String("ftp://access.engr.oregonstate.edu/");
      
       //String url = new String("3ht:hi-mom.com/");
       String url = new String("http://www.google.com/");
       //String url = new String("http::///www.google.com/");
       //String url = new String("http://!!!/");
       System.out.println("TESTING URL: " + url);
       System.out.println(thing.isValid(url));	   
   }
   
   
   //let's first test a null string before moving to more advanced concepts
   public void testPartitionOne()
   {
	   UrlValidator urlVal = new UrlValidator();
	   assertFalse(urlVal.isValid(null));

   }
   
   //check a valid URL 
   public void testPartitionTwo()
   {
	   UrlValidator urlVal = new UrlValidator();

	   String url = new String("http://www.google.com/path");
	   System.out.println("TESTING VALID URL: " + url);
       System.out.println(urlVal.isValid(url));
	   
  }

   //check the scheme
   public void testPartitionThree(){
	   UrlValidator urlVal = new UrlValidator();
	 
	 String url = new String("wut://www.google.com/path");
	 System.out.println("TESTING BAD SCHEME: " + url);
     System.out.println(urlVal.isValid(url));
  
  }
 
   //check the authority
   public void testPartitionFour(){
	 UrlValidator urlVal = new UrlValidator();
	 
	 String url = new String("http://www.W.U/T.com/path");
	 System.out.println("TESTING BAD AUTHORITY: " + url);
     System.out.println(urlVal.isValid(url));
  
  }

   //check the port 
   public void testPartitionFive(){
	   UrlValidator urlVal = new UrlValidator();
	   
	   //should return true
	   String url = new String("http://www.google.com:80");
	   System.out.println("TESTING VALID PORT: " + url);
       System.out.println(urlVal.isValid(url));
       
       //should return false, improper format
       String url1 = new String("http://www.google.com80");
	   System.out.println("TESTING INVALID PORT: " + url1);
       System.out.println(urlVal.isValid(url1));
	   
       //should return false, invalid number
       String url2 = new String("http://www.google.com:-1");
	   System.out.println("TESTING INVALID PORT: " + url2);
       System.out.println(urlVal.isValid(url2));
       
       //should return false, invalid number
       String url3 = new String("http://www.google.com:70000");
	   System.out.println("TESTING INVALID PORT: " + url3);
       System.out.println(urlVal.isValid(url3));
       
     //should return true
	   String url4 = new String("http://www.google.com:65535");
	   System.out.println("TESTING VALID PORT: " + url4);
       System.out.println(urlVal.isValid(url4));
  }

 //check the path
   public void testPartitionSix(){
	   UrlValidator urlVal = new UrlValidator();
	 
	 String url = new String("http://www.google.com/..");
	 System.out.println("TESTING BAD PATH: " + url);
     System.out.println(urlVal.isValid(url));
  
  }
 
   //check the query
   public void testPartitionSeven(){
	   UrlValidator urlVal = new UrlValidator();
	 
	 String url = new String("http://www.google.com/path?test");
	 System.out.println("TESTING VALID QUERY: " + url);
     System.out.println(urlVal.isValid(url));
  
     String url1 = new String("http://www.google.com/path¿test");
	 System.out.println("TESTING INVALID QUERY: " + url1);
	 System.out.println(urlVal.isValid(url1));
  }   
   
   
   public void testIsValid()
   {
       // Test strategy:
       // Build an array of 4 partitions with a bad at 0 and good at 1 and 2
       // Use for loop to iterate and ensure bad are bad and good are good
       String [] prefixArr = new String[] {"htp://", "http://", ""};
       String [] wwwArr = new String[] {"/w$w/.", "www.", ""};
       String [] siteArr = new String[] {"!!!", "bobble", "google"};
       String [] endArr = new String[] {".!", ".com", ".net"};
      
       UrlValidator thing = new UrlValidator();
      
       for (int a = 0; a < prefixArr.length; a++) {
           for (int b = 0; b < wwwArr.length; b++) {
               for (int c = 0; c < siteArr.length; c++) {
                   for (int d = 0; d < endArr.length; d++) {
                      
                       //Build url changing each time
                       String url = new String(prefixArr[a]+wwwArr[b]+siteArr[c]+endArr[d]);
                       boolean result = thing.isValid(url);
                      
                       System.out.println("TESTING URL: " + url);
                       if((a==0 || b==0 || c==0 || d==0) && result==true) {
                       System.out.println("MISMATCH on " + url);
                       System.out.println("Showed up as " + result + " but should be " + !result);
                      
                       }
                       else {
                          
                           System.out.println("TEST OK with " + result);
                       }
                       System.out.println("\n");
                   }
               }
           }
       }  
  } 
}

