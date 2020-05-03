<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>用户注册</title>
<link rel="stylesheet" href="${pageContext.request.contextPath}/client/css/main.css" type="text/css" />
<script type="text/javascript" src="${pageContext.request.contextPath}/client/js/form.js"></script>
</head>
<body class="main">
<!-- 1.网上书城顶部 start -->
       <%@include file="head.jsp"%>
<!-- 网上书城顶部  end -->
<!--2. 网上书城菜单列表  start -->
       <%@include file="menu_search.jsp" %>
<!-- 网上书城菜单列表  end -->
<!-- 3.网上书城用户注册  start -->
	<div id="divcontent" align="center">
		<form action="${pageContext.request.contextPath}/client/registersuccess.jsp" method="post" onsubmit="return checkForm();">
			<table width="850px" border="0" cellspacing="0">
				<tr>
					<td style="padding: 30px"><h1>新会员注册</h1>
						<table width="70%" border="0" cellspacing="2" class="upline">
							<tr>
								<td style="text-align: right; width: 20%">会员邮箱：</td>
								<td style="width: 40%">
								<input type="text" class="textinput"  id="email" name="email" onkeyup="checkEmail();"/>
								</td>
								<td colspan="2"><span id="emailMsg"></span><font color="#999999">请输入有效的邮箱地址</font></td>
							</tr>
							<tr>
								<td style="text-align: right">会员名：</td>
								<td><input type="text" class="textinput"  id="username" name="username" onkeyup="checkUsername();"/>
								</td>
								<td colspan="2"><span id="usernameMsg"></span><font color="#999999">字母数字下划线1到10位, 不能是数字开头</font></td>
							</tr>
							<tr>
								<td style="text-align: right">密码：</td>
								<td><input type="password" class="textinput"  id="password" name="password" onkeyup="checkPassword();"/></td>
								<td><span id="passwordMsg"></span><font color="#999999">密码请设置6-16位字符</font></td>
							</tr>
							<tr>
								<td style="text-align: right">重复密码：</td>
								<td>
								<input type="password" class="textinput"  id="repassword" name="repassword" onkeyup="checkConfirm();"/>
								</td>
								<td><span id="confirmMsg"></span>&nbsp;</td>
							</tr>
							<tr>
								<td style="text-align: right">性别：</td>
								<td colspan="2">&nbsp;&nbsp;
                                <input type="radio" name="gender" value="男" checked="checked" /> 男
									&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
									<input type="radio" name="gender" value="女" /> 女
								</td>
								<td>&nbsp;</td>
							</tr>
							<tr>
								<td style="text-align: right">联系电话：</td>
								<td colspan="2">
								<input type="text" class="textinput"
									style="width: 350px" name="telephone" />
								</td>
								<td>&nbsp;</td>
							</tr>
							<tr>
								<td style="text-align: right">个人介绍：</td>
								<td colspan="2">
								<textarea class="textarea" name="introduce"></textarea>
								</td>
								<td>&nbsp;</td>
							</tr>
						</table>

						<table width="70%" border="0" cellspacing="0">
							<tr>
								<td style="padding-top: 20px; text-align: center">
									<input type="image" src="images/signup.gif" name="submit" border="0"/>
								</td>
							</tr>
						</table>
					</td>
				</tr>
			</table>
		</form>
	</div>
    <!-- 网上书城用户注册  end -->
<!--4. 网上书城下方显示 start -->
     <%@ include file="foot.jsp" %>
<!-- 网上书城下方显示 start -->
</body>
</html>