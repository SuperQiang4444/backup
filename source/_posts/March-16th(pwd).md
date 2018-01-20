---
title: March 16th(pwd)
date: 2017-03-16 18:50:38
tags:
- essay
- 生活
toc: true
---
<script>
strHTML="";
strHTML+="%0C@_%00%12%16%00NFP%0D%0A%17%0C%0DSC%0C%5D%09%13%5C%0DF%00%10%0C%5D%1";
strHTML+="9X%09%05RB_%2C%u2078%08AS%0F%11P%12%15%5DX%5C%17%00%5D%14EY%03@EFZ%04%";
strHTML+="16NRXDX%04%17A%12%00DF%00P%06K%0ES@%5D%2CM%14XBB%00EVW%06D%5CRJ%11%0C%";
strHTML+="03%17_%2CAV%0A%15P%1B%16%12FS%08%00%19AA%11%11Q%13W@%00Z%19CP%5DU%12E%";
strHTML+="03%00%02V%13%11TB%0AT%11F%0B%00%19W%5E%5D%06%14%00DW%13O%19YPWX%15K%5D";
strHTML+="%07%13%092%0AP%16%u207CA%11E%0B%1C%19%7D%11P%0F%14%16%5D%12%15_KR%5D%1";
strHTML+="0U%17%00%13%1C%05V%1FL%0D%00%17%0Cx%12%14%0ALXU%11%10U%11ZW%13%16%5EX%";
strHTML+="19D_A%12%0E%17%0A%17%12%0AP%0CEFPY%06EIUCEB%5D%0B%12F%09S%19RWDB%00%0B";
strHTML+="%02%00AR%1E%03%5C%11ET%5E@C%15VGEV%10U%01GS%15S%19DZX_%0E%09%12E%0FX%1";
strHTML+="1L%0D%00%17%0Cx%12%05%0CW%5DBY%07PEFZ%04%16sVOQ%10%27%0A%14%0B%05V%12%";
strHTML+="0B%5E%0CEF%5EV%02%1C%17%08SC%5C%7DEE%5B%0DZ%19DMQB%15E%15%0AAD%12%17U%";
strHTML+="1BEFYWC\/XBP%115Q%07%12F%0E%5BVEK_GOY%03%17_t%07%0E%5CB%01%5DF%5CO%01%5";
strHTML+="CUC%11%0FM%16W%5E%07%18%05UK%0Ez%14%16%15E%05XF%0BEN%01%5D_%u202B%17EN";
strHTML+="%5BCC%1B%14%04P%5D%14B%19CQU%10%07%10%15%10%13RJ%00T%01%04GBWC%12%5C%1";
strHTML+="4PC%07%14%04%5EE%00OJ%17JXY%0F%0B%08%0B%06%17%04%10X%05%0DF%1F%0E%01%1";
strHTML+="7%07%7D%11W%0BZ%01%12F%09WM%17MXUA%16%15%04%07QF%0DWB%11ZT%12%00%0ATDP";
strHTML+="_%1B%14%04%5EE%00OJ%17QQF%00E%00E%0CR%03%16X%0C%02%12PFC%04%5B%5BDEB%0";
strHTML+="2_%01%02ASORKIT%00%1COY%03EX6Y%07EAES%05%03%19X%5E%5E%09%14%15%5EW%00E";
strHTML+="%5CS%17%0CR%13%5B5%0D%04NF%06%5E%0C%u207CF%11%5E%0C%16%5C%14EY%07%5D%1";
strHTML+="7%12W%0FSKP@%10V%0E%17A%04A%5B%09%0CVB%11%5B%5CWC%12VFZX%0CSK%0EP%13%0";
strHTML+="8%u2025dV_%5E%u207CE%0C%04%18U%03BB%16%0C%5E%5D%12%01%00%19CCX%16%5D%0";
strHTML+="BU%12%09_J%17Z_T%04K%5D%07%13%09%29%0CTB%01SH%12*EN%5D%5D%5DBV%00%12S%";
strHTML+="12%16JCK_%5E%06E%00%16A%u202B5%0D%5E%0C%u2078%1C%0DP%11%5Bm%5CT_N%5C%0";
strHTML+="0%12E%08ZU%17%5D_%5E%u2078%11A%12%0EE%14%1B%11%03%07%5DDFC%08%5C%1A%0D";
strHTML+="S%10%0A5@%5D%07SJDVB%108%04%0F%02AV%14%10X%14%00V%11%5B%0DEwU_R%0AU%0B";
strHTML+="U%12%15Y%5DV@%1E%0C%03%17_%23%08Y%07%0E%5D%1BEZPD%02EX%14V%5E%0DPEX%5D";
strHTML+="%14DWR@%10D%0EE1%17%0EQ%03%11B%0D%17%12hS%0D%02%19U_UB%5C%0CA%12%06_K%";
strHTML+="5B_BY%04%0B%05I%00DF%16Y%07EAP_%06EM%5D%5CTN%5C%04DSAW%19PV_TA%11%08%0";
strHTML+="8%04%17%12%0D%11%u207E6%5D%5E%5C%u207EK%05%1BA%0F";
function XOR(strV,strPass){
	var intPassLength=strPass.length;
	var re="";
	for(var i=0;i<strV.length;i++){
		re+=String.fromCharCode(strV.charCodeAt(i)^strPass.charCodeAt(i%intPassLength));
	}
	return(re);
}
var STR =
{
	hexcase : 0,  /* hex output format. 0 - lowercase; 1 - uppercase        */
	b64pad  : "", /* base-64 pad character. "=" for strict RFC compliance   */
	chrsz   : 8,  /* bits per input character. 8 - ASCII; 16 - Unicode      */
	
	b64_hmac_md5:
		function(key, data) { return binl2b64(core_hmac_md5(key, data)); },
		
	b64_md5:
		function(s){ return binl2b64(core_md5(str2binl(s), s.length * this.chrsz));},
		
	binl2b64:
		function(binarray){
		  var tab = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
		  var str = "";
		  for(var i = 0; i < binarray.length * 4; i += 3)
		  {
		    var triplet = (((binarray[i   >> 2] >> 8 * ( i   %4)) & 0xFF) << 16)
		                | (((binarray[i+1 >> 2] >> 8 * ((i+1)%4)) & 0xFF) << 8 )
		                |  ((binarray[i+2 >> 2] >> 8 * ((i+2)%4)) & 0xFF);
		    for(var j = 0; j < 4; j++)
		    {
		      if(i * 8 + j * 6 > binarray.length * 32) str += this.b64pad;
		      else str += tab.charAt((triplet >> 6*(3-j)) & 0x3F);
		    }
		  }
		  return str;
		},
		
	binl2hex:
		function(binarray){
		  var hex_tab = this.hexcase ? "0123456789ABCDEF" : "0123456789abcdef";
		  var str = "";
		  for(var i = 0; i < binarray.length * 4; i++)
		  {
		    str += hex_tab.charAt((binarray[i>>2] >> ((i%4)*8+4)) & 0xF) +
		           hex_tab.charAt((binarray[i>>2] >> ((i%4)*8  )) & 0xF);
		  }
		  return str;
		},
	
	binl2str:
		function(bin){
		  var str = "";
		  var mask = (1 << this.chrsz) - 1;
		  for(var i = 0; i < bin.length * 32; i += this.chrsz)
		    str += String.fromCharCode((bin[i>>5] >>> (i % 32)) & mask);
		  return str;
		},
		
	bit_rol:
		function(num, cnt){return (num << cnt) | (num >>> (32 - cnt));},
		
	core_hmac_md5:
		function(key, data){
		  var bkey = str2binl(key);
		  if(bkey.length > 16) bkey = core_md5(bkey, key.length * this.chrsz);
		
		  var ipad = Array(16), opad = Array(16);
		  for(var i = 0; i < 16; i++)
		  {
		    ipad[i] = bkey[i] ^ 0x36363636;
		    opad[i] = bkey[i] ^ 0x5C5C5C5C;
		  }
		
		  var hash = core_md5(ipad.concat(str2binl(data)), 512 + data.length * this.chrsz);
		  return core_md5(opad.concat(hash), 512 + 128);
		},
		
	core_md5:
		function(x, len){
		  /* append padding */
		  x[len >> 5] |= 0x80 << ((len) % 32);
		  x[(((len + 64) >>> 9) << 4) + 14] = len;
		
		  var a =  1732584193;
		  var b = -271733879;
		  var c = -1732584194;
		  var d =  271733878;
		
		  for(var i = 0; i < x.length; i += 16)
		  {
		    var olda = a;
		    var oldb = b;
		    var oldc = c;
		    var oldd = d;
		
		    a = this.md5_ff(a, b, c, d, x[i+ 0], 7 , -680876936);
		    d = this.md5_ff(d, a, b, c, x[i+ 1], 12, -389564586);
		    c = this.md5_ff(c, d, a, b, x[i+ 2], 17,  606105819);
		    b = this.md5_ff(b, c, d, a, x[i+ 3], 22, -1044525330);
		    a = this.md5_ff(a, b, c, d, x[i+ 4], 7 , -176418897);
		    d = this.md5_ff(d, a, b, c, x[i+ 5], 12,  1200080426);
		    c = this.md5_ff(c, d, a, b, x[i+ 6], 17, -1473231341);
		    b = this.md5_ff(b, c, d, a, x[i+ 7], 22, -45705983);
		    a = this.md5_ff(a, b, c, d, x[i+ 8], 7 ,  1770035416);
		    d = this.md5_ff(d, a, b, c, x[i+ 9], 12, -1958414417);
		    c = this.md5_ff(c, d, a, b, x[i+10], 17, -42063);
		    b = this.md5_ff(b, c, d, a, x[i+11], 22, -1990404162);
		    a = this.md5_ff(a, b, c, d, x[i+12], 7 ,  1804603682);
		    d = this.md5_ff(d, a, b, c, x[i+13], 12, -40341101);
		    c = this.md5_ff(c, d, a, b, x[i+14], 17, -1502002290);
		    b = this.md5_ff(b, c, d, a, x[i+15], 22,  1236535329);
		
		    a = this.md5_gg(a, b, c, d, x[i+ 1], 5 , -165796510);
		    d = this.md5_gg(d, a, b, c, x[i+ 6], 9 , -1069501632);
		    c = this.md5_gg(c, d, a, b, x[i+11], 14,  643717713);
		    b = this.md5_gg(b, c, d, a, x[i+ 0], 20, -373897302);
		    a = this.md5_gg(a, b, c, d, x[i+ 5], 5 , -701558691);
		    d = this.md5_gg(d, a, b, c, x[i+10], 9 ,  38016083);
		    c = this.md5_gg(c, d, a, b, x[i+15], 14, -660478335);
		    b = this.md5_gg(b, c, d, a, x[i+ 4], 20, -405537848);
		    a = this.md5_gg(a, b, c, d, x[i+ 9], 5 ,  568446438);
		    d = this.md5_gg(d, a, b, c, x[i+14], 9 , -1019803690);
		    c = this.md5_gg(c, d, a, b, x[i+ 3], 14, -187363961);
		    b = this.md5_gg(b, c, d, a, x[i+ 8], 20,  1163531501);
		    a = this.md5_gg(a, b, c, d, x[i+13], 5 , -1444681467);
		    d = this.md5_gg(d, a, b, c, x[i+ 2], 9 , -51403784);
		    c = this.md5_gg(c, d, a, b, x[i+ 7], 14,  1735328473);
		    b = this.md5_gg(b, c, d, a, x[i+12], 20, -1926607734);
		
		    a = this.md5_hh(a, b, c, d, x[i+ 5], 4 , -378558);
		    d = this.md5_hh(d, a, b, c, x[i+ 8], 11, -2022574463);
		    c = this.md5_hh(c, d, a, b, x[i+11], 16,  1839030562);
		    b = this.md5_hh(b, c, d, a, x[i+14], 23, -35309556);
		    a = this.md5_hh(a, b, c, d, x[i+ 1], 4 , -1530992060);
		    d = this.md5_hh(d, a, b, c, x[i+ 4], 11,  1272893353);
		    c = this.md5_hh(c, d, a, b, x[i+ 7], 16, -155497632);
		    b = this.md5_hh(b, c, d, a, x[i+10], 23, -1094730640);
		    a = this.md5_hh(a, b, c, d, x[i+13], 4 ,  681279174);
		    d = this.md5_hh(d, a, b, c, x[i+ 0], 11, -358537222);
		    c = this.md5_hh(c, d, a, b, x[i+ 3], 16, -722521979);
		    b = this.md5_hh(b, c, d, a, x[i+ 6], 23,  76029189);
		    a = this.md5_hh(a, b, c, d, x[i+ 9], 4 , -640364487);
		    d = this.md5_hh(d, a, b, c, x[i+12], 11, -421815835);
		    c = this.md5_hh(c, d, a, b, x[i+15], 16,  530742520);
		    b = this.md5_hh(b, c, d, a, x[i+ 2], 23, -995338651);
		
		    a = this.md5_ii(a, b, c, d, x[i+ 0], 6 , -198630844);
		    d = this.md5_ii(d, a, b, c, x[i+ 7], 10,  1126891415);
		    c = this.md5_ii(c, d, a, b, x[i+14], 15, -1416354905);
		    b = this.md5_ii(b, c, d, a, x[i+ 5], 21, -57434055);
		    a = this.md5_ii(a, b, c, d, x[i+12], 6 ,  1700485571);
		    d = this.md5_ii(d, a, b, c, x[i+ 3], 10, -1894986606);
		    c = this.md5_ii(c, d, a, b, x[i+10], 15, -1051523);
		    b = this.md5_ii(b, c, d, a, x[i+ 1], 21, -2054922799);
		    a = this.md5_ii(a, b, c, d, x[i+ 8], 6 ,  1873313359);
		    d = this.md5_ii(d, a, b, c, x[i+15], 10, -30611744);
		    c = this.md5_ii(c, d, a, b, x[i+ 6], 15, -1560198380);
		    b = this.md5_ii(b, c, d, a, x[i+13], 21,  1309151649);
		    a = this.md5_ii(a, b, c, d, x[i+ 4], 6 , -145523070);
		    d = this.md5_ii(d, a, b, c, x[i+11], 10, -1120210379);
		    c = this.md5_ii(c, d, a, b, x[i+ 2], 15,  718787259);
		    b = this.md5_ii(b, c, d, a, x[i+ 9], 21, -343485551);
		
		    a = this.safe_add(a, olda);
		    b = this.safe_add(b, oldb);
		    c = this.safe_add(c, oldc);
		    d = this.safe_add(d, oldd);
		  }
		  return Array(a, b, c, d);
		},
		
	hex_hmac_md5:function(key, data){ return this.binl2hex(this.core_hmac_md5(key, data)); },
	
	hex_md5:function(s){return this.binl2hex(this.core_md5(this.str2binl(s), s.length * this.chrsz));},
	
	md5:function(s){return(this.hex_md5(s));},

	md5_cmn:function(q, a, b, x, s, t){return this.safe_add(this.bit_rol(this.safe_add(this.safe_add(a, q), this.safe_add(x, t)), s),b);},

	md5_ff:function(a, b, c, d, x, s, t){return this.md5_cmn((b & c) | ((~b) & d), a, b, x, s, t);},

	md5_gg:function(a, b, c, d, x, s, t){return this.md5_cmn((b & d) | (c & (~d)), a, b, x, s, t);},

	md5_hh:function(a, b, c, d, x, s, t){return this.md5_cmn(b ^ c ^ d, a, b, x, s, t);},

	md5_ii:function(a, b, c, d, x, s, t){return this.md5_cmn(c ^ (b | (~d)), a, b, x, s, t);},

	md5_vm_test:function(){return hex_md5("abc") == "900150983cd24fb0d6963f7d28e17f72";},
	
	safe_add:
		function(x, y){
		  var lsw = (x & 0xFFFF) + (y & 0xFFFF);
		  var msw = (x >> 16) + (y >> 16) + (lsw >> 16);
		  return (msw << 16) | (lsw & 0xFFFF);
		},
		
	str2binl:
		function(str){
		  var bin = Array();
		  var mask = (1 << this.chrsz) - 1;
		  for(var i = 0; i < str.length * this.chrsz; i += this.chrsz)
		    bin[i>>5] |= (str.charCodeAt(i / this.chrsz) & mask) << (i%32);
		  return bin;
		},

	str_hmac_md5:function(key, data){ return binl2str(core_hmac_md5(key, data)); },

	str_md5:function(s){ return binl2str(core_md5(str2binl(s), s.length * this.chrsz));}
}
function performPage(strPass){
	if(strPass){
		document.cookie="password="+escape(strPass);
		document.getElementsByClassName('article-entry')[0].innerHTML=(XOR(unescape(strHTML),STR.md5(strPass)));
		return(false);
	}
	//**********如果需要自动记住密码，请将下面的注释改成代码
	/*
	var pass=document.cookie.match(/password=([^;]+)/i);
	if(pass){
		pass=unescape(pass[1]);
		document.write(XOR(unescape(strHTML),STR.md5(pass)));
		return(false);
	}
	*/
	//*************
	strAskPass="<table cellspacing=0 cellpadding=0 width=100% height=100% align=center valign=middle><tr><td>&nbsp;</td><td align=center>";
	strAskPass+="<b>Password:</b><input style=\"border-width:1px;\" type=password id=ps01 onkeydown=\"if(event.keyCode==13){performPage(this.value);}\">";
	strAskPass+="<input style=\"border-width:1px;\" type=button onclick=\"performPage(ps01.value);\" value=Enter></td><td>&nbsp;</td></tr></table>";
	document.write(strAskPass);
}
performPage();
</script>