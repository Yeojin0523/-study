<!-- 20220803 컴퓨터학과 정여진 -->
<!-- 엣지 최적화 -->
<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<html lang="kor">
<head>
<meta charset="UTF-8">
<meta name="viewport" content="width=device-width, initial-scale=1.0">
<title>page_control_03</title>
</head>
<body>
	<%
	String URL =request.getParameter("value");
	String login_id = request.getParameter("id");
	String login_pwd = request.getParameter("pwd");
	URL += "&" + "value" + URL + "&" + "id=" + "&" + login_id + "&" + "pwd=" + login_pwd;
	response.sendRedirect(URL);
	%>
</body>
</html>