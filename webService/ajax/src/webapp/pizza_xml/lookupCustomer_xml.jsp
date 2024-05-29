<%@ page contentType="text/xml; charset=utf-8" %>
<%@ page import="example.ajax.pizza.*,java.util.*" %>
<%! @SuppressWarnings("unchecked") %>
<%
/*
Customer_old[] customers = new Customer_old[] {
    new Customer_old("Doug Henderson",
                "7804 Jumping Hill Lane",
                "Dallas", "Texas", "75218"),
    new Customer_old("Mary Jenkins",
                "7081 Teakwood #24C",
                "Dallas", "Texas", "75182"),
    new Customer_old("John Jacobs",
                "234 East Rutherford Drive",
                "Topeka", "Kansas", "66608"),
    new Customer_old("Happy Traum",
                "876 Links Circle",
                "Topeka", "Kansas", "66608")
};
*/

// application에서 "custMap" 객체 검색
Map<String, Customer> custMap 
    = (Map<String, Customer>) application.getAttribute("custMap"); 

if (custMap == null) {  // "custMap"이 존재하지 않으면 새로 생성
    //Set up some customers to use 
    custMap = new HashMap<String, Customer>();
    // string은 전화번호, customer는 정보들
    custMap.put("010-111-1111", 
            new Customer("Doug Henderson",
            	new Address(
                "7804 Jumping Hill Lane",
                "Dallas", "Texas", "75218"), "010-111-1111",
            	"no-recent-order")
    );
    custMap.put("010-222-2222", 
            new Customer("Mary Jenkins",
            	new Address(
                "7081 Teakwood #24C",
                "Dallas", "Texas", "75182"), "010-222-2222",
            	"no-recent-order")
    );
    custMap.put("010-333-3333", 
            new Customer("John Jacobs",
                new Address(
            	"234 East Rutherford Drive",
                "Topeka", "Kansas", "66608"), "010-333-3333", 
                "no-recent-order")
    );
    custMap.put("010-444-4444", 
            new Customer("Happy Traum",
            	new Address(
                "876 Links Circle",
                "Topeka", "Kansas", "66608"), "010-444-4444",
            	"no-recent-order")
    );  
/*  
    for (Customer_old c : customers) {      // 배열에 저장된 Customer 객체들을 custMap에 저장
        custMap.put(c.getPhone(), c);       
    } 
*/    
    application.setAttribute("custMap", custMap);   // "custMap"을 application에 저장
}

String phone = request.getParameter("phone");
System.out.println("phone number: " + phone);   

//find a customer having the given phone number
Customer c = custMap.get(phone);    // "custMap"에서 검색
if (c != null) {                // unregistered customer
	/*
    String result = c.getName() + "\n" + c.getAddress();
    System.out.println("result: " + result);
    out.clearBuffer();
    out.print(result);
    */
%>
<result> 
 <name><%=c.getName()%></name>
 <address>
 <street><%=c.getAddress().getStreet()%></street>
 <city><%=c.getAddress().getCity()%></city>
 <state><%=c.getAddress().getState()%></state>
 <zipCode><%=c.getAddress().getZipCode()%></zipCode>
 </address>
 <recentOrder><%=c.getRecentOrder()%></recentOrder>
</result>
<%
} else {
    response.setStatus(400);        // bad request
    response.addHeader("Status", "Unregistered customer");
}
/*
// 참고: Jackson2를 이용한 object-to-JSON 변환
ObjectMapper mapper = new ObjectMapper();
String result2 = mapper.writeValueAsString(c);
System.out.println(result2);        // 변환 결과 확인
*/
%>
