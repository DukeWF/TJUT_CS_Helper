var receiverAddressObj;
var receiverNameObj;
var receiverPhoneObj;

window.onload = function() {	// 页面加载之后, 获取页面中的对象
	receiverAddressObj = document.getElementById("receiverAddress");
	receiverNameObj = document.getElementById("receiverName");
	receiverPhoneObj = document.getElementById("receiverPhone");
};

function checkOnSubmit() {			// 验证整个表单
	var receiverAddress = checkReceiverAddress();
	var receiverName = checkReceiverName();
	var receiverPhone = checkReceiverPhone();
	if(receiverAddress && receiverName && receiverPhone){
		document.getElementById("orderForm").submit();
	}else{
	   return "";
	}
}

function checkReceiverAddress() {			// 验证收获地址
	var value =receiverAddressObj.value;
	var msg = "";
	if (!value)
		msg = "收获地址必须填写";	
	receiverAddressMsg.innerHTML = msg;
	receiverAddressObj.parentNode.parentNode.style.color = msg == "" ? "black" : "red";
	return msg == "";
}

function checkReceiverName() {		// 验证收货人
	var value =receiverNameObj.value;
	var msg = "";
	if (!value)
		msg = "收获人必须填写";	
	receiverNameMsg.innerHTML = msg;
	receiverNameObj.parentNode.parentNode.style.color = msg == "" ? "black" : "red";
	return msg == "";
}

function checkReceiverPhone() {		// 验证联系方式
	var regex =/^1[3,5,8]\d{9}$/;	//以13、15、18开头的手机号
	var value =receiverPhoneObj.value;
	var msg = "";
	if (!value)
		msg = "联系方式必须填写";
	else if (!regex.test(value))
		msg = "手机号码不合法：";
	receiverPhoneMsg.innerHTML = msg;
	receiverPhoneObj.parentNode.parentNode.style.color = msg == "" ? "black" : "red";
	return msg == "";
}
