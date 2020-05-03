function typeset(str)//文字排版正则替换
{
    //修正不规则标点
    str = str.replace(/,/gi, "，");
    str = str.replace(/\.\r/gi, "。\r");
    str = str.replace(/．/gi, "。");
    str = str.replace(/;/gi, "；");
    str = str.replace(/\"/gi, "＂");
    str = str.replace(/\'/gi, "｀");
    str = str.replace(/!/gi, "！");
    str = str.replace(/\(/gi, "（");
    str = str.replace(/\)/gi, "）");
    str = str.replace(/【/gi, "「");
    str = str.replace(/『/gi, "「");
    str = str.replace(/】/gi, "」");
    str = str.replace(/』/gi, "」");
    //修正不规则换行，其中 。？！…」”）\n\r 为有效换行标志符．（注意：此代码将破坏所有无效标点换行）
    //str = str.replace(/([^。？！…」”）\n\r])[\n\r]{2}/gi, "$1");
    //修正不规则段落
    str = "\n" + str;
    str = str.replace(/[\n|\r]+[ |　|\t]*/gi, "\n\n　　");
    str = str.replace("\n\n", "");

    return str;
}

function clientclick() {
    if (window.event.keyCode == 13) {
        window.event.keyCode = 9;
        return true;
    }
}

function shouchang() {
    window.external.AddFavorite(document.location.href, document.title)
}

function feixiang() {
    var str = "我发现了一篇比较有用的文章，赶快看看吧！"
    str = str + '\r\n\r\n' + '引用标题：' + document.title;
    str = str + '\r\n' + '引用地址：' + document.location.href;
    clipboardData.setData('text', str);
    alert('本章标题与地址已经复制到您的粘贴板了，赶快将它复制到您要分享的地方吧：）');
}

function ajaxComment(type) {

    var id = location.href.substring(location.href.lastIndexOf("/") + 3);
    var xmlhttprequest;
    if (window.XMLHttpRequest) {
        xmlhttprequest = new XMLHttpRequest();
    }
    else {
        xmlhttprequest = new ActiveXObject("Microsoft.XMLHTTP");
    }

    xmlhttprequest.onreadystatechange = function() {
        if (xmlhttprequest.readyState == 4 && xmlhttprequest.status == 200) {
            document.getElementById("div_comment").innerHTML = xmlhttprequest.responseText;
            document.getElementById("div_wait").style.display = "none";
        }
    }

    xmlhttprequest.open("GET", "/Handler/GetComment.ashx?ID=" + id + "&type=" + type + "&random" + Math.random(), true);
    xmlhttprequest.send(null);
}

function ajaxCount(sourcetype) {
    var xmlhttprequest;
    if (window.XMLHttpRequest) {
        xmlhttprequest = new XMLHttpRequest();
    }
    else {
        xmlhttprequest = new ActiveXObject("Microsoft.XMLHTTP");
    }

    xmlhttprequest.onreadystatechange = function() {
        if (xmlhttprequest.readyState == 4 && xmlhttprequest.status == 200) {
            if (sourcetype == 1) {
                document.getElementById("count_js").innerText = xmlhttprequest.responseText;
            }
            else if (sourcetype == 2) {
                document.getElementById("count_jc").innerText = xmlhttprequest.responseText;
            }
            else if (sourcetype == 3) {
                document.getElementById("count_xiazai").innerText = xmlhttprequest.responseText;
            }
        }
    }

    xmlhttprequest.open("GET", "/Handler/GetCount.ashx?sourcetype=" + sourcetype + "&random" + Math.random(), true);
    xmlhttprequest.send(null);
}

function defaultonload() {
    ajaxCount(1);
    ajaxCount(2);
    ajaxCount(3);
}

var cname = document.location.href;
var _begindate = GetCookie(cname);

if (_begindate == "" || _begindate == "NaN") {
    SetCookie(cname);
}
else {
    var begindate = new Date(parseInt(_begindate));
    var enddate = new Date();
    var diffdate = enddate.getTime() - begindate.getTime();

    if (parseInt(diffdate) / 1000 < 10) {
        alert("你刷新的太快了");
    }
    else {
        SetCookie(cname);
    }
}

function SetCookie(cname) {
    var Days = 1;
    var exp = new Date();
    exp.setTime(exp.getTime() + Days * 24 * 60 * 60 * 1000);
    var begindate = new Date();
    document.cookie = cname + "=" + begindate.getTime() + ";expires=" + exp.toGMTString();
}

function GetCookie(cname) {//获取单个cookies
    //js获取cookie
    var acookie = document.cookie.split("; ");
    for (var i = 0; i < acookie.length; i++) {
        var arr = acookie[i].split("=");
        if (cname == arr[0]) {
            if (arr.length > 1) {
                return unescape(arr[1]);
            }
            else {
                return "";
            }
        }
    }
    return "";
}