
//获取ID
var $ = function (id) {return typeof id === "string" ? document.getElementById(id) : id;};
//获取tagName
var $$ = function (tagName, oParent) {return (oParent || document).getElementsByTagName(tagName);};
//自动播放对象
var AutoPlay = function (id) {this.initialize(id);};
AutoPlay.prototype = {
	initialize: function (id)
	{
		var oThis = this;
		this.oBox = $(id);
		this.oUl = $$("ul", this.oBox)[0];
		this.aImg = $$("img", this.oBox);
		this.timer = null;
		this.autoTimer = null;
		this.iNow = 0;
		this.creatBtn();
		this.aBtn = $$("li", this.oCount);
		this.toggle();
		this.autoTimer = setInterval(function ()
		{
			oThis.next();
		}, 3000);
		this.oBox.onmouseover = function ()
		{
			clearInterval(oThis.autoTimer);
		};
		this.oBox.onmouseout = function ()
		{
			oThis.autoTimer = setInterval(function ()
			{
				oThis.next();
			}, 3000);
		};
		for (var i = 0; i < this.aBtn.length; i++)
		{
			this.aBtn[i].index = i;
			this.aBtn[i].onmouseover = function ()
			{
				oThis.iNow = this.index;
				oThis.toggle();
			};
		}
	},
	creatBtn: function ()
	{
		this.oCount = document.createElement("ul");
		this.oFrag = document.createDocumentFragment();
		this.oCount.className = "count";
		for (var i = 0; i < this.aImg.length; i++)
		{
			var oLi = document.createElement("li");
			oLi.innerHTML = i + 1;
			this.oFrag.appendChild(oLi);
		}
		this.oCount.appendChild(this.oFrag);
		this.oBox.appendChild(this.oCount);
	},
	toggle: function ()
	{
		for (var i = 0; i < this.aBtn.length; i++) this.aBtn[i].className = "";
		this.aBtn[this.iNow].className = "current";
		this.doMove(-(this.iNow * this.aImg[0].offsetHeight));
	},
	next: function ()
	{
		this.iNow++;
		this.iNow == this.aBtn.length && (this.iNow = 0);
		this.toggle();
	},
	doMove: function (iTarget)
	{
		var oThis = this;
		clearInterval(oThis.timer);
		oThis.timer = setInterval(function ()
		{
			var iSpeed = (iTarget - oThis.oUl.offsetTop) / 5;
			iSpeed = iSpeed > 0 ? Math.ceil(iSpeed) : Math.floor(iSpeed);
			oThis.oUl.offsetTop == iTarget ? clearInterval(oThis.timer) : (oThis.oUl.style.top = oThis.oUl.offsetTop + iSpeed + "px");
		}, 30);
	}
};
window.onload = function ()
{
	new AutoPlay("box_autoplay");
};