<%@ page language="java" pageEncoding="GBK"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 
Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
    <head>
    <title>�û�ע��</title>
    <style type="text/css">
        h3 {
	        margin-left: 100px;
        }
        #outer {
	        width: 750px;
        }
        span {
	        color: #ff0000
        }
        div {
             height:20px;
	        margin-bottom: 10px;
        }
        .ch {
	        width: 80px;
	        text-align: right;
	        float: left;
        }
        .ip {
	        width: 500px;
	        float: left
        }
        .ip>input {
	        margin-right: 20px
        }
        #bt {
	        margin-left: 50px;
        }
        #bt>input {
	        margin-right: 30px;
        }
    </style>
</head>
<body>
	    <form action="ControllerServlet" method="post">
		    <h3>�û�ע��</h3>
		    <div id="outer">
			    <div>
				    <div class="ch">����:</div>
				    <div class="ip">
				<input type="text" name="name" value="${formBean.name }" />
					    <span>${formBean.errors.name}${DBMes}</span>
				    </div>
			    </div>
			    <div>
				    <div class="ch">����:</div>
				    <div class="ip">
					    <input type="password" name="password" />
					    <span>${formBean.errors.password}</span>
				    </div>
			    </div>
			    <div>
				    <div class="ch">ȷ������:</div>
				    <div class="ip">
					    <input type="password" name="password2" />
					    <span>${formBean.errors.password2}</span>
				    </div>
			    </div>
			    <div>
				    <div class="ch">����:</div>
				    <div class="ip">
			<input type="text" name="email" value="${formBean.email }" />
					    <span>${formBean.errors.email}</span>
				    </div>
			    </div>
			    <div id="bt">
				    <input type="reset" value="���� " />
				    <input type="submit" value="ע��" />
			    </div>
		    </div>
	    </form>
</body>
</html>
