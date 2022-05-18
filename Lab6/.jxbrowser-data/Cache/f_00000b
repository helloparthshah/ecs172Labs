(function(){/*

 Copyright The Closure Library Authors.
 SPDX-License-Identifier: Apache-2.0
*/
'use strict';var l;function aa(a){var b=0;return function(){return b<a.length?{done:!1,value:a[b++]}:{done:!0}}}
var ba="function"==typeof Object.defineProperties?Object.defineProperty:function(a,b,c){if(a==Array.prototype||a==Object.prototype)return a;a[b]=c.value;return a};
function ca(a){a=["object"==typeof globalThis&&globalThis,a,"object"==typeof window&&window,"object"==typeof self&&self,"object"==typeof global&&global];for(var b=0;b<a.length;++b){var c=a[b];if(c&&c.Math==Math)return c}throw Error("Cannot find global object");}
var da=ca(this);function n(a,b){if(b)a:{var c=da;a=a.split(".");for(var d=0;d<a.length-1;d++){var e=a[d];if(!(e in c))break a;c=c[e]}a=a[a.length-1];d=c[a];b=b(d);b!=d&&null!=b&&ba(c,a,{configurable:!0,writable:!0,value:b})}}
n("Symbol",function(a){function b(f){if(this instanceof b)throw new TypeError("Symbol is not a constructor");return new c(d+(f||"")+"_"+e++,f)}
function c(f,g){this.i=f;ba(this,"description",{configurable:!0,writable:!0,value:g})}
if(a)return a;c.prototype.toString=function(){return this.i};
var d="jscomp_symbol_"+(1E9*Math.random()>>>0)+"_",e=0;return b});
n("Symbol.iterator",function(a){if(a)return a;a=Symbol("Symbol.iterator");for(var b="Array Int8Array Uint8Array Uint8ClampedArray Int16Array Uint16Array Int32Array Uint32Array Float32Array Float64Array".split(" "),c=0;c<b.length;c++){var d=da[b[c]];"function"===typeof d&&"function"!=typeof d.prototype[a]&&ba(d.prototype,a,{configurable:!0,writable:!0,value:function(){return ea(aa(this))}})}return a});
function ea(a){a={next:a};a[Symbol.iterator]=function(){return this};
return a}
function q(a){var b="undefined"!=typeof Symbol&&Symbol.iterator&&a[Symbol.iterator];return b?b.call(a):{next:aa(a)}}
function fa(a){if(!(a instanceof Array)){a=q(a);for(var b,c=[];!(b=a.next()).done;)c.push(b.value);a=c}return a}
function ha(a,b){return Object.prototype.hasOwnProperty.call(a,b)}
var ia="function"==typeof Object.assign?Object.assign:function(a,b){for(var c=1;c<arguments.length;c++){var d=arguments[c];if(d)for(var e in d)ha(d,e)&&(a[e]=d[e])}return a};
n("Object.assign",function(a){return a||ia});
var ja="function"==typeof Object.create?Object.create:function(a){function b(){}
b.prototype=a;return new b},la=function(){function a(){function c(){}
new c;Reflect.construct(c,[],function(){});
return new c instanceof c}
if("undefined"!=typeof Reflect&&Reflect.construct){if(a())return Reflect.construct;var b=Reflect.construct;return function(c,d,e){c=b(c,d);e&&Reflect.setPrototypeOf(c,e.prototype);return c}}return function(c,d,e){void 0===e&&(e=c);
e=ja(e.prototype||Object.prototype);return Function.prototype.apply.call(c,e,d)||e}}(),ma;
if("function"==typeof Object.setPrototypeOf)ma=Object.setPrototypeOf;else{var na;a:{var oa={a:!0},pa={};try{pa.__proto__=oa;na=pa.a;break a}catch(a){}na=!1}ma=na?function(a,b){a.__proto__=b;if(a.__proto__!==b)throw new TypeError(a+" is not extensible");return a}:null}var qa=ma;
function r(a,b){a.prototype=ja(b.prototype);a.prototype.constructor=a;if(qa)qa(a,b);else for(var c in b)if("prototype"!=c)if(Object.defineProperties){var d=Object.getOwnPropertyDescriptor(b,c);d&&Object.defineProperty(a,c,d)}else a[c]=b[c];a.Y=b.prototype}
function ra(){this.F=!1;this.m=null;this.j=void 0;this.i=1;this.s=this.o=0;this.B=this.l=null}
function sa(a){if(a.F)throw new TypeError("Generator is already running");a.F=!0}
ra.prototype.v=function(a){this.j=a};
function ta(a,b){a.l={xb:b,Cb:!0};a.i=a.o||a.s}
ra.prototype.return=function(a){this.l={return:a};this.i=this.s};
function t(a,b,c){a.i=c;return{value:b}}
ra.prototype.u=function(a){this.i=a};
function ua(a,b,c){a.o=b;void 0!=c&&(a.s=c)}
function xa(a,b){a.i=b;a.o=0}
function ya(a){a.o=0;var b=a.l.xb;a.l=null;return b}
function za(a){a.B=[a.l];a.o=0;a.s=0}
function Aa(a){var b=a.B.splice(0)[0];(b=a.l=a.l||b)?b.Cb?a.i=a.o||a.s:void 0!=b.u&&a.s<b.u?(a.i=b.u,a.l=null):a.i=a.s:a.i=0}
function Ba(a){this.i=new ra;this.j=a}
function Ca(a,b){sa(a.i);var c=a.i.m;if(c)return Ea(a,"return"in c?c["return"]:function(d){return{value:d,done:!0}},b,a.i.return);
a.i.return(b);return Fa(a)}
function Ea(a,b,c,d){try{var e=b.call(a.i.m,c);if(!(e instanceof Object))throw new TypeError("Iterator result "+e+" is not an object");if(!e.done)return a.i.F=!1,e;var f=e.value}catch(g){return a.i.m=null,ta(a.i,g),Fa(a)}a.i.m=null;d.call(a.i,f);return Fa(a)}
function Fa(a){for(;a.i.i;)try{var b=a.j(a.i);if(b)return a.i.F=!1,{value:b.value,done:!1}}catch(c){a.i.j=void 0,ta(a.i,c)}a.i.F=!1;if(a.i.l){b=a.i.l;a.i.l=null;if(b.Cb)throw b.xb;return{value:b.return,done:!0}}return{value:void 0,done:!0}}
function Ga(a){this.next=function(b){sa(a.i);a.i.m?b=Ea(a,a.i.m.next,b,a.i.v):(a.i.v(b),b=Fa(a));return b};
this.throw=function(b){sa(a.i);a.i.m?b=Ea(a,a.i.m["throw"],b,a.i.v):(ta(a.i,b),b=Fa(a));return b};
this.return=function(b){return Ca(a,b)};
this[Symbol.iterator]=function(){return this}}
function Ha(a){function b(d){return a.next(d)}
function c(d){return a.throw(d)}
return new Promise(function(d,e){function f(g){g.done?d(g.value):Promise.resolve(g.value).then(b,c).then(f,e)}
f(a.next())})}
function w(a){return Ha(new Ga(new Ba(a)))}
function Ia(){for(var a=Number(this),b=[],c=a;c<arguments.length;c++)b[c-a]=arguments[c];return b}
n("Reflect",function(a){return a?a:{}});
n("Reflect.construct",function(){return la});
n("Reflect.setPrototypeOf",function(a){return a?a:qa?function(b,c){try{return qa(b,c),!0}catch(d){return!1}}:null});
n("Promise",function(a){function b(g){this.i=0;this.l=void 0;this.j=[];this.F=!1;var h=this.m();try{g(h.resolve,h.reject)}catch(k){h.reject(k)}}
function c(){this.i=null}
function d(g){return g instanceof b?g:new b(function(h){h(g)})}
if(a)return a;c.prototype.j=function(g){if(null==this.i){this.i=[];var h=this;this.l(function(){h.s()})}this.i.push(g)};
var e=da.setTimeout;c.prototype.l=function(g){e(g,0)};
c.prototype.s=function(){for(;this.i&&this.i.length;){var g=this.i;this.i=[];for(var h=0;h<g.length;++h){var k=g[h];g[h]=null;try{k()}catch(m){this.m(m)}}}this.i=null};
c.prototype.m=function(g){this.l(function(){throw g;})};
b.prototype.m=function(){function g(m){return function(p){k||(k=!0,m.call(h,p))}}
var h=this,k=!1;return{resolve:g(this.R),reject:g(this.s)}};
b.prototype.R=function(g){if(g===this)this.s(new TypeError("A Promise cannot resolve to itself"));else if(g instanceof b)this.ea(g);else{a:switch(typeof g){case "object":var h=null!=g;break a;case "function":h=!0;break a;default:h=!1}h?this.N(g):this.o(g)}};
b.prototype.N=function(g){var h=void 0;try{h=g.then}catch(k){this.s(k);return}"function"==typeof h?this.na(h,g):this.o(g)};
b.prototype.s=function(g){this.v(2,g)};
b.prototype.o=function(g){this.v(1,g)};
b.prototype.v=function(g,h){if(0!=this.i)throw Error("Cannot settle("+g+", "+h+"): Promise already settled in state"+this.i);this.i=g;this.l=h;2===this.i&&this.W();this.B()};
b.prototype.W=function(){var g=this;e(function(){if(g.L()){var h=da.console;"undefined"!==typeof h&&h.error(g.l)}},1)};
b.prototype.L=function(){if(this.F)return!1;var g=da.CustomEvent,h=da.Event,k=da.dispatchEvent;if("undefined"===typeof k)return!0;"function"===typeof g?g=new g("unhandledrejection",{cancelable:!0}):"function"===typeof h?g=new h("unhandledrejection",{cancelable:!0}):(g=da.document.createEvent("CustomEvent"),g.initCustomEvent("unhandledrejection",!1,!0,g));g.promise=this;g.reason=this.l;return k(g)};
b.prototype.B=function(){if(null!=this.j){for(var g=0;g<this.j.length;++g)f.j(this.j[g]);this.j=null}};
var f=new c;b.prototype.ea=function(g){var h=this.m();g.Ka(h.resolve,h.reject)};
b.prototype.na=function(g,h){var k=this.m();try{g.call(h,k.resolve,k.reject)}catch(m){k.reject(m)}};
b.prototype.then=function(g,h){function k(x,v){return"function"==typeof x?function(E){try{m(x(E))}catch(G){p(G)}}:v}
var m,p,u=new b(function(x,v){m=x;p=v});
this.Ka(k(g,m),k(h,p));return u};
b.prototype.catch=function(g){return this.then(void 0,g)};
b.prototype.Ka=function(g,h){function k(){switch(m.i){case 1:g(m.l);break;case 2:h(m.l);break;default:throw Error("Unexpected state: "+m.i);}}
var m=this;null==this.j?f.j(k):this.j.push(k);this.F=!0};
b.resolve=d;b.reject=function(g){return new b(function(h,k){k(g)})};
b.race=function(g){return new b(function(h,k){for(var m=q(g),p=m.next();!p.done;p=m.next())d(p.value).Ka(h,k)})};
b.all=function(g){var h=q(g),k=h.next();return k.done?d([]):new b(function(m,p){function u(E){return function(G){x[E]=G;v--;0==v&&m(x)}}
var x=[],v=0;do x.push(void 0),v++,d(k.value).Ka(u(x.length-1),p),k=h.next();while(!k.done)})};
return b});
n("WeakMap",function(a){function b(k){this.i=(h+=Math.random()+1).toString();if(k){k=q(k);for(var m;!(m=k.next()).done;)m=m.value,this.set(m[0],m[1])}}
function c(){}
function d(k){var m=typeof k;return"object"===m&&null!==k||"function"===m}
function e(k){if(!ha(k,g)){var m=new c;ba(k,g,{value:m})}}
function f(k){var m=Object[k];m&&(Object[k]=function(p){if(p instanceof c)return p;Object.isExtensible(p)&&e(p);return m(p)})}
if(function(){if(!a||!Object.seal)return!1;try{var k=Object.seal({}),m=Object.seal({}),p=new a([[k,2],[m,3]]);if(2!=p.get(k)||3!=p.get(m))return!1;p.delete(k);p.set(m,4);return!p.has(k)&&4==p.get(m)}catch(u){return!1}}())return a;
var g="$jscomp_hidden_"+Math.random();f("freeze");f("preventExtensions");f("seal");var h=0;b.prototype.set=function(k,m){if(!d(k))throw Error("Invalid WeakMap key");e(k);if(!ha(k,g))throw Error("WeakMap key fail: "+k);k[g][this.i]=m;return this};
b.prototype.get=function(k){return d(k)&&ha(k,g)?k[g][this.i]:void 0};
b.prototype.has=function(k){return d(k)&&ha(k,g)&&ha(k[g],this.i)};
b.prototype.delete=function(k){return d(k)&&ha(k,g)&&ha(k[g],this.i)?delete k[g][this.i]:!1};
return b});
n("Map",function(a){function b(){var h={};return h.previous=h.next=h.head=h}
function c(h,k){var m=h.i;return ea(function(){if(m){for(;m.head!=h.i;)m=m.previous;for(;m.next!=m.head;)return m=m.next,{done:!1,value:k(m)};m=null}return{done:!0,value:void 0}})}
function d(h,k){var m=k&&typeof k;"object"==m||"function"==m?f.has(k)?m=f.get(k):(m=""+ ++g,f.set(k,m)):m="p_"+k;var p=h.data_[m];if(p&&ha(h.data_,m))for(h=0;h<p.length;h++){var u=p[h];if(k!==k&&u.key!==u.key||k===u.key)return{id:m,list:p,index:h,entry:u}}return{id:m,list:p,index:-1,entry:void 0}}
function e(h){this.data_={};this.i=b();this.size=0;if(h){h=q(h);for(var k;!(k=h.next()).done;)k=k.value,this.set(k[0],k[1])}}
if(function(){if(!a||"function"!=typeof a||!a.prototype.entries||"function"!=typeof Object.seal)return!1;try{var h=Object.seal({x:4}),k=new a(q([[h,"s"]]));if("s"!=k.get(h)||1!=k.size||k.get({x:4})||k.set({x:4},"t")!=k||2!=k.size)return!1;var m=k.entries(),p=m.next();if(p.done||p.value[0]!=h||"s"!=p.value[1])return!1;p=m.next();return p.done||4!=p.value[0].x||"t"!=p.value[1]||!m.next().done?!1:!0}catch(u){return!1}}())return a;
var f=new WeakMap;e.prototype.set=function(h,k){h=0===h?0:h;var m=d(this,h);m.list||(m.list=this.data_[m.id]=[]);m.entry?m.entry.value=k:(m.entry={next:this.i,previous:this.i.previous,head:this.i,key:h,value:k},m.list.push(m.entry),this.i.previous.next=m.entry,this.i.previous=m.entry,this.size++);return this};
e.prototype.delete=function(h){h=d(this,h);return h.entry&&h.list?(h.list.splice(h.index,1),h.list.length||delete this.data_[h.id],h.entry.previous.next=h.entry.next,h.entry.next.previous=h.entry.previous,h.entry.head=null,this.size--,!0):!1};
e.prototype.clear=function(){this.data_={};this.i=this.i.previous=b();this.size=0};
e.prototype.has=function(h){return!!d(this,h).entry};
e.prototype.get=function(h){return(h=d(this,h).entry)&&h.value};
e.prototype.entries=function(){return c(this,function(h){return[h.key,h.value]})};
e.prototype.keys=function(){return c(this,function(h){return h.key})};
e.prototype.values=function(){return c(this,function(h){return h.value})};
e.prototype.forEach=function(h,k){for(var m=this.entries(),p;!(p=m.next()).done;)p=p.value,h.call(k,p[1],p[0],this)};
e.prototype[Symbol.iterator]=e.prototype.entries;var g=0;return e});
function Ja(a,b,c){if(null==a)throw new TypeError("The 'this' value for String.prototype."+c+" must not be null or undefined");if(b instanceof RegExp)throw new TypeError("First argument to String.prototype."+c+" must not be a regular expression");return a+""}
n("String.prototype.endsWith",function(a){return a?a:function(b,c){var d=Ja(this,b,"endsWith");b+="";void 0===c&&(c=d.length);c=Math.max(0,Math.min(c|0,d.length));for(var e=b.length;0<e&&0<c;)if(d[--c]!=b[--e])return!1;return 0>=e}});
n("Array.prototype.find",function(a){return a?a:function(b,c){a:{var d=this;d instanceof String&&(d=String(d));for(var e=d.length,f=0;f<e;f++){var g=d[f];if(b.call(c,g,f,d)){b=g;break a}}b=void 0}return b}});
n("String.prototype.startsWith",function(a){return a?a:function(b,c){var d=Ja(this,b,"startsWith");b+="";var e=d.length,f=b.length;c=Math.max(0,Math.min(c|0,d.length));for(var g=0;g<f&&c<e;)if(d[c++]!=b[g++])return!1;return g>=f}});
n("Number.isFinite",function(a){return a?a:function(b){return"number"!==typeof b?!1:!isNaN(b)&&Infinity!==b&&-Infinity!==b}});
n("Number.isInteger",function(a){return a?a:function(b){return Number.isFinite(b)?b===Math.floor(b):!1}});
n("Number.MAX_SAFE_INTEGER",function(){return 9007199254740991});
function Ka(a,b){a instanceof String&&(a+="");var c=0,d=!1,e={next:function(){if(!d&&c<a.length){var f=c++;return{value:b(f,a[f]),done:!1}}d=!0;return{done:!0,value:void 0}}};
e[Symbol.iterator]=function(){return e};
return e}
n("Array.prototype.entries",function(a){return a?a:function(){return Ka(this,function(b,c){return[b,c]})}});
n("Number.isNaN",function(a){return a?a:function(b){return"number"===typeof b&&isNaN(b)}});
n("Object.setPrototypeOf",function(a){return a||qa});
n("Set",function(a){function b(c){this.i=new Map;if(c){c=q(c);for(var d;!(d=c.next()).done;)this.add(d.value)}this.size=this.i.size}
if(function(){if(!a||"function"!=typeof a||!a.prototype.entries||"function"!=typeof Object.seal)return!1;try{var c=Object.seal({x:4}),d=new a(q([c]));if(!d.has(c)||1!=d.size||d.add(c)!=d||1!=d.size||d.add({x:4})!=d||2!=d.size)return!1;var e=d.entries(),f=e.next();if(f.done||f.value[0]!=c||f.value[1]!=c)return!1;f=e.next();return f.done||f.value[0]==c||4!=f.value[0].x||f.value[1]!=f.value[0]?!1:e.next().done}catch(g){return!1}}())return a;
b.prototype.add=function(c){c=0===c?0:c;this.i.set(c,c);this.size=this.i.size;return this};
b.prototype.delete=function(c){c=this.i.delete(c);this.size=this.i.size;return c};
b.prototype.clear=function(){this.i.clear();this.size=0};
b.prototype.has=function(c){return this.i.has(c)};
b.prototype.entries=function(){return this.i.entries()};
b.prototype.values=function(){return this.i.values()};
b.prototype.keys=b.prototype.values;b.prototype[Symbol.iterator]=b.prototype.values;b.prototype.forEach=function(c,d){var e=this;this.i.forEach(function(f){return c.call(d,f,f,e)})};
return b});
n("Object.entries",function(a){return a?a:function(b){var c=[],d;for(d in b)ha(b,d)&&c.push([d,b[d]]);return c}});
n("Array.prototype.keys",function(a){return a?a:function(){return Ka(this,function(b){return b})}});
n("Array.prototype.values",function(a){return a?a:function(){return Ka(this,function(b,c){return c})}});
n("Array.from",function(a){return a?a:function(b,c,d){c=null!=c?c:function(h){return h};
var e=[],f="undefined"!=typeof Symbol&&Symbol.iterator&&b[Symbol.iterator];if("function"==typeof f){b=f.call(b);for(var g=0;!(f=b.next()).done;)e.push(c.call(d,f.value,g++))}else for(f=b.length,g=0;g<f;g++)e.push(c.call(d,b[g],g));return e}});
n("Object.is",function(a){return a?a:function(b,c){return b===c?0!==b||1/b===1/c:b!==b&&c!==c}});
n("Array.prototype.includes",function(a){return a?a:function(b,c){var d=this;d instanceof String&&(d=String(d));var e=d.length;c=c||0;for(0>c&&(c=Math.max(c+e,0));c<e;c++){var f=d[c];if(f===b||Object.is(f,b))return!0}return!1}});
n("String.prototype.includes",function(a){return a?a:function(b,c){return-1!==Ja(this,b,"includes").indexOf(b,c||0)}});
n("Object.values",function(a){return a?a:function(b){var c=[],d;for(d in b)ha(b,d)&&c.push(b[d]);return c}});
var y=this||self;function z(a,b,c){a=a.split(".");c=c||y;a[0]in c||"undefined"==typeof c.execScript||c.execScript("var "+a[0]);for(var d;a.length&&(d=a.shift());)a.length||void 0===b?c[d]&&c[d]!==Object.prototype[d]?c=c[d]:c=c[d]={}:c[d]=b}
function A(a,b){a=a.split(".");b=b||y;for(var c=0;c<a.length;c++)if(b=b[a[c]],null==b)return null;return b}
function La(a){a.fb=void 0;a.getInstance=function(){return a.fb?a.fb:a.fb=new a}}
function Ma(a){var b=typeof a;return"object"!=b?b:a?Array.isArray(a)?"array":b:"null"}
function Na(a){var b=Ma(a);return"array"==b||"object"==b&&"number"==typeof a.length}
function Pa(a){var b=typeof a;return"object"==b&&null!=a||"function"==b}
function Qa(a){return Object.prototype.hasOwnProperty.call(a,Ra)&&a[Ra]||(a[Ra]=++Sa)}
var Ra="closure_uid_"+(1E9*Math.random()>>>0),Sa=0;function Ta(a,b,c){return a.call.apply(a.bind,arguments)}
function Ua(a,b,c){if(!a)throw Error();if(2<arguments.length){var d=Array.prototype.slice.call(arguments,2);return function(){var e=Array.prototype.slice.call(arguments);Array.prototype.unshift.apply(e,d);return a.apply(b,e)}}return function(){return a.apply(b,arguments)}}
function Va(a,b,c){Function.prototype.bind&&-1!=Function.prototype.bind.toString().indexOf("native code")?Va=Ta:Va=Ua;return Va.apply(null,arguments)}
function Wa(a,b){var c=Array.prototype.slice.call(arguments,1);return function(){var d=c.slice();d.push.apply(d,arguments);return a.apply(this,d)}}
function Xa(a,b){function c(){}
c.prototype=b.prototype;a.Y=b.prototype;a.prototype=new c;a.prototype.constructor=a;a.mp=function(d,e,f){for(var g=Array(arguments.length-2),h=2;h<arguments.length;h++)g[h-2]=arguments[h];return b.prototype[e].apply(d,g)}}
function Ya(a){return a}
;function Za(a,b){if(Error.captureStackTrace)Error.captureStackTrace(this,Za);else{var c=Error().stack;c&&(this.stack=c)}a&&(this.message=String(a));void 0!==b&&(this.Sb=b)}
Xa(Za,Error);Za.prototype.name="CustomError";function $a(a){a=a.url;var b=/[?&]dsh=1(&|$)/.test(a);this.l=!b&&/[?&]ae=1(&|$)/.test(a);this.m=!b&&/[?&]ae=2(&|$)/.test(a);if((this.i=/[?&]adurl=([^&]*)/.exec(a))&&this.i[1]){try{var c=decodeURIComponent(this.i[1])}catch(d){c=null}this.j=c}}
;function ab(){}
function bb(a){var b=!1,c;return function(){b||(c=a(),b=!0);return c}}
;var cb=Array.prototype.indexOf?function(a,b){return Array.prototype.indexOf.call(a,b,void 0)}:function(a,b){if("string"===typeof a)return"string"!==typeof b||1!=b.length?-1:a.indexOf(b,0);
for(var c=0;c<a.length;c++)if(c in a&&a[c]===b)return c;return-1},db=Array.prototype.forEach?function(a,b,c){Array.prototype.forEach.call(a,b,c)}:function(a,b,c){for(var d=a.length,e="string"===typeof a?a.split(""):a,f=0;f<d;f++)f in e&&b.call(c,e[f],f,a)},eb=Array.prototype.filter?function(a,b){return Array.prototype.filter.call(a,b,void 0)}:function(a,b){for(var c=a.length,d=[],e=0,f="string"===typeof a?a.split(""):a,g=0;g<c;g++)if(g in f){var h=f[g];
b.call(void 0,h,g,a)&&(d[e++]=h)}return d},fb=Array.prototype.map?function(a,b){return Array.prototype.map.call(a,b,void 0)}:function(a,b){for(var c=a.length,d=Array(c),e="string"===typeof a?a.split(""):a,f=0;f<c;f++)f in e&&(d[f]=b.call(void 0,e[f],f,a));
return d},gb=Array.prototype.reduce?function(a,b,c){return Array.prototype.reduce.call(a,b,c)}:function(a,b,c){var d=c;
db(a,function(e,f){d=b.call(void 0,d,e,f,a)});
return d};
function hb(a,b){a:{for(var c=a.length,d="string"===typeof a?a.split(""):a,e=0;e<c;e++)if(e in d&&b.call(void 0,d[e],e,a)){b=e;break a}b=-1}return 0>b?null:"string"===typeof a?a.charAt(b):a[b]}
function ib(a,b){b=cb(a,b);var c;(c=0<=b)&&Array.prototype.splice.call(a,b,1);return c}
function jb(a,b){for(var c=1;c<arguments.length;c++){var d=arguments[c];if(Na(d)){var e=a.length||0,f=d.length||0;a.length=e+f;for(var g=0;g<f;g++)a[e+g]=d[g]}else a.push(d)}}
;function kb(a,b){for(var c in a)b.call(void 0,a[c],c,a)}
function lb(a){var b=mb,c;for(c in b)if(a.call(void 0,b[c],c,b))return c}
function nb(a){for(var b in a)return!1;return!0}
function ob(a,b){if(null!==a&&b in a)throw Error('The object already contains the key "'+b+'"');a[b]=!0}
function pb(a){return null!==a&&"privembed"in a?a.privembed:!1}
function qb(a,b){for(var c in a)if(!(c in b)||a[c]!==b[c])return!1;for(var d in b)if(!(d in a))return!1;return!0}
function rb(a){var b={},c;for(c in a)b[c]=a[c];return b}
function ub(a){if(!a||"object"!==typeof a)return a;if("function"===typeof a.clone)return a.clone();if("undefined"!==typeof Map&&a instanceof Map)return new Map(a);if("undefined"!==typeof Set&&a instanceof Set)return new Set(a);var b=Array.isArray(a)?[]:"function"!==typeof ArrayBuffer||"function"!==typeof ArrayBuffer.isView||!ArrayBuffer.isView(a)||a instanceof DataView?{}:new a.constructor(a.length),c;for(c in a)b[c]=ub(a[c]);return b}
var vb="constructor hasOwnProperty isPrototypeOf propertyIsEnumerable toLocaleString toString valueOf".split(" ");function wb(a,b){for(var c,d,e=1;e<arguments.length;e++){d=arguments[e];for(c in d)a[c]=d[c];for(var f=0;f<vb.length;f++)c=vb[f],Object.prototype.hasOwnProperty.call(d,c)&&(a[c]=d[c])}}
;var xb;function yb(){if(void 0===xb){var a=null,b=y.trustedTypes;if(b&&b.createPolicy){try{a=b.createPolicy("goog#html",{createHTML:Ya,createScript:Ya,createScriptURL:Ya})}catch(c){y.console&&y.console.error(c.message)}xb=a}else xb=a}return xb}
;function zb(a,b){this.l=a===Ab&&b||""}
zb.prototype.j=!0;zb.prototype.i=function(){return this.l};
function Bb(a){return new zb(Ab,a)}
var Ab={};Bb("");var Cb={};function Db(a){this.l=Cb===Cb?a:"";this.j=!0}
Db.prototype.i=function(){return this.l.toString()};
Db.prototype.toString=function(){return this.l.toString()};function Eb(a,b){this.l=b===Fb?a:""}
Eb.prototype.j=!0;Eb.prototype.i=function(){return this.l.toString()};
Eb.prototype.toString=function(){return this.l+""};
function Gb(a){if(a instanceof Eb&&a.constructor===Eb)return a.l;Ma(a);return"type_error:TrustedResourceUrl"}
var Fb={};function Hb(a){var b=yb();a=b?b.createScriptURL(a):a;return new Eb(a,Fb)}
;var Ib=String.prototype.trim?function(a){return a.trim()}:function(a){return/^[\s\xa0]*([\s\S]*?)[\s\xa0]*$/.exec(a)[1]};function Jb(a,b){this.l=b===Kb?a:""}
Jb.prototype.j=!0;Jb.prototype.i=function(){return this.l.toString()};
Jb.prototype.toString=function(){return this.l.toString()};
function Lb(a){if(a instanceof Jb&&a.constructor===Jb)return a.l;Ma(a);return"type_error:SafeUrl"}
var Ob=/^(?:(?:https?|mailto|ftp):|[^:/?#]*(?:[/?#]|$))/i,Kb={};function Pb(){var a=y.navigator;return a&&(a=a.userAgent)?a:""}
function B(a){return-1!=Pb().indexOf(a)}
;function Qb(){return(B("Chrome")||B("CriOS"))&&!B("Edge")||B("Silk")}
;var Rb={};function Sb(a){this.l=Rb===Rb?a:"";this.j=!0}
Sb.prototype.i=function(){return this.l.toString()};
Sb.prototype.toString=function(){return this.l.toString()};function Tb(a,b){b instanceof Jb||b instanceof Jb||(b="object"==typeof b&&b.j?b.i():String(b),Ob.test(b)||(b="about:invalid#zClosurez"),b=new Jb(b,Kb));a.href=Lb(b)}
function Ub(a,b){a.rel="stylesheet";a.href=Gb(b).toString();(b=Vb('style[nonce],link[rel="stylesheet"][nonce]',a.ownerDocument&&a.ownerDocument.defaultView))&&a.setAttribute("nonce",b)}
function Wb(){return Vb("script[nonce]")}
var Xb=/^[\w+/_-]+[=]{0,2}$/;function Vb(a,b){b=(b||y).document;return b.querySelector?(a=b.querySelector(a))&&(a=a.nonce||a.getAttribute("nonce"))&&Xb.test(a)?a:"":""}
;function Yb(a){for(var b=0,c=0;c<a.length;++c)b=31*b+a.charCodeAt(c)>>>0;return b}
;var Zb=RegExp("^(?:([^:/?#.]+):)?(?://(?:([^\\\\/?#]*)@)?([^\\\\/?#]*?)(?::([0-9]+))?(?=[\\\\/?#]|$))?([^?#]+)?(?:\\?([^#]*))?(?:#([\\s\\S]*))?$");function $b(a){return a?decodeURI(a):a}
function ac(a,b){return b.match(Zb)[a]||null}
function bc(a){return $b(ac(3,a))}
function cc(a){var b=a.match(Zb);a=b[5];var c=b[6];b=b[7];var d="";a&&(d+=a);c&&(d+="?"+c);b&&(d+="#"+b);return d}
function dc(a,b,c){if(Array.isArray(b))for(var d=0;d<b.length;d++)dc(a,String(b[d]),c);else null!=b&&c.push(a+(""===b?"":"="+encodeURIComponent(String(b))))}
function ec(a){var b=[],c;for(c in a)dc(c,a[c],b);return b.join("&")}
function fc(a,b){b=ec(b);if(b){var c=a.indexOf("#");0>c&&(c=a.length);var d=a.indexOf("?");if(0>d||d>c){d=c;var e=""}else e=a.substring(d+1,c);a=[a.slice(0,d),e,a.slice(c)];c=a[1];a[1]=b?c?c+"&"+b:b:c;b=a[0]+(a[1]?"?"+a[1]:"")+a[2]}else b=a;return b}
function gc(a,b,c,d){for(var e=c.length;0<=(b=a.indexOf(c,b))&&b<d;){var f=a.charCodeAt(b-1);if(38==f||63==f)if(f=a.charCodeAt(b+e),!f||61==f||38==f||35==f)return b;b+=e+1}return-1}
var hc=/#|$/,ic=/[?&]($|#)/;function jc(a){for(var b=a.search(hc),c=0,d,e=[];0<=(d=gc(a,c,"key",b));)e.push(a.substring(c,d)),c=Math.min(a.indexOf("&",d)+1||b,b);e.push(a.slice(c));return e.join("").replace(ic,"$1")}
;var kc={};function lc(a){if(a!==kc)throw Error("requires a valid immutable API token");}
;function pc(){return B("iPhone")&&!B("iPod")&&!B("iPad")}
;function qc(a){qc[" "](a);return a}
qc[" "]=function(){};var rc=B("Opera"),sc=B("Trident")||B("MSIE"),tc=B("Edge"),uc=B("Gecko")&&!(-1!=Pb().toLowerCase().indexOf("webkit")&&!B("Edge"))&&!(B("Trident")||B("MSIE"))&&!B("Edge"),vc=-1!=Pb().toLowerCase().indexOf("webkit")&&!B("Edge"),wc=B("Android");function xc(){var a=y.document;return a?a.documentMode:void 0}
var yc;a:{var zc="",Ac=function(){var a=Pb();if(uc)return/rv:([^\);]+)(\)|;)/.exec(a);if(tc)return/Edge\/([\d\.]+)/.exec(a);if(sc)return/\b(?:MSIE|rv)[: ]([^\);]+)(\)|;)/.exec(a);if(vc)return/WebKit\/(\S+)/.exec(a);if(rc)return/(?:Version)[ \/]?(\S+)/.exec(a)}();
Ac&&(zc=Ac?Ac[1]:"");if(sc){var Bc=xc();if(null!=Bc&&Bc>parseFloat(zc)){yc=String(Bc);break a}}yc=zc}var Cc=yc,Dc;if(y.document&&sc){var Ec=xc();Dc=Ec?Ec:parseInt(Cc,10)||void 0}else Dc=void 0;var Fc=Dc;var Gc=pc()||B("iPod"),Hc=B("iPad");!B("Android")||Qb();Qb();var Ic=B("Safari")&&!(Qb()||B("Coast")||B("Opera")||B("Edge")||B("Edg/")||B("OPR")||B("Firefox")||B("FxiOS")||B("Silk")||B("Android"))&&!(pc()||B("iPad")||B("iPod"));var Jc={},Kc=null;
function Lc(a,b){Na(a);void 0===b&&(b=0);if(!Kc){Kc={};for(var c="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789".split(""),d=["+/=","+/","-_=","-_.","-_"],e=0;5>e;e++){var f=c.concat(d[e].split(""));Jc[e]=f;for(var g=0;g<f.length;g++){var h=f[g];void 0===Kc[h]&&(Kc[h]=g)}}}b=Jc[b];c=Array(Math.floor(a.length/3));d=b[64]||"";for(e=f=0;f<a.length-2;f+=3){var k=a[f],m=a[f+1];h=a[f+2];g=b[k>>2];k=b[(k&3)<<4|m>>4];m=b[(m&15)<<2|h>>6];h=b[h&63];c[e++]=""+g+k+m+h}g=0;h=d;switch(a.length-
f){case 2:g=a[f+1],h=b[(g&15)<<2]||d;case 1:a=a[f],c[e]=""+b[a>>2]+b[(a&3)<<4|g>>4]+h+d}return c.join("")}
;var Mc="undefined"!==typeof Uint8Array,Nc={};var Oc;function Pc(a){if(Nc!==Nc)throw Error("illegal external caller");this.da=a;if(null!==a&&0===a.length)throw Error("ByteString should be constructed with non-empty values");}
Pc.prototype.isEmpty=function(){return null==this.da};var Qc="function"===typeof Symbol&&"symbol"===typeof Symbol()?Symbol(void 0):void 0;function Rc(a,b){Object.isFrozen(a)||(Qc?a[Qc]|=b:void 0!==a.Oa?a.Oa|=b:Object.defineProperties(a,{Oa:{value:b,configurable:!0,writable:!0,enumerable:!1}}))}
function Sc(a){var b;Qc?b=a[Qc]:b=a.Oa;return null==b?0:b}
function Tc(a){return Array.isArray(a)?!!(Sc(a)&1):!1}
function Uc(a){Rc(a,1);return a}
function Vc(a){return Array.isArray(a)?!!(Sc(a)&2):!1}
function Zc(a){if(!Array.isArray(a))throw Error("cannot mark non-array as immutable");Rc(a,2)}
;function $c(a){return null!==a&&"object"===typeof a&&!Array.isArray(a)&&a.constructor===Object}
var ad,bd=Object.freeze(Uc([]));function cd(a){if(Vc(a.A))throw Error("Cannot mutate an immutable Message");}
var dd="undefined"!=typeof Symbol&&"undefined"!=typeof Symbol.hasInstance;function ed(a){return{value:a,configurable:!1,writable:!1,enumerable:!1}}
;function fd(a){y.setTimeout(function(){throw a;},0)}
;function gd(a,b,c){c=void 0===c?!1:c;if(Array.isArray(a))return new b(a);if(c)return new b}
;function hd(a){switch(typeof a){case "number":return isFinite(a)?a:String(a);case "object":if(a&&!Array.isArray(a)){if(Mc&&null!=a&&a instanceof Uint8Array)return Lc(a);if(a instanceof Pc){var b=a.da;null!=b&&"string"!==typeof b&&(Mc&&b instanceof Uint8Array?b=Lc(b):(Ma(b),b=null));return(a.da=b)||""}}}return a}
;function id(a,b){b=void 0===b?jd:b;return kd(a,b)}
function ld(a,b){if(null!=a){if(Array.isArray(a))a=kd(a,b);else if($c(a)){var c={},d;for(d in a)c[d]=ld(a[d],b);a=c}else a=b(a);return a}}
function kd(a,b){for(var c=a.slice(),d=0;d<c.length;d++)c[d]=ld(c[d],b);Tc(a)&&Uc(c);return c}
function md(a){if(a&&"object"==typeof a&&a.toJSON)return a.toJSON();a=hd(a);return Array.isArray(a)?id(a,md):a}
function jd(a){return Mc&&null!=a&&a instanceof Uint8Array?new Uint8Array(a):a}
;function nd(a){return a.j||(a.j=a.A[a.l+a.ja]={})}
function od(a,b,c){return-1===b?null:b>=a.l?a.j?a.j[b]:void 0:(void 0===c?0:c)&&a.j&&(c=a.j[b],null!=c)?c:a.A[b+a.ja]}
function C(a,b,c,d,e){d=void 0===d?!1:d;(void 0===e?0:e)||cd(a);b<a.l&&!d?a.A[b+a.ja]=c:nd(a)[b]=c;return a}
function pd(a,b,c,d){c=void 0===c?!0:c;var e=od(a,b,d);null==e&&(e=bd);if(Vc(a.A))c&&(Zc(e),Object.freeze(e));else if(e===bd||Vc(e))e=Uc(e.slice()),C(a,b,e,d);return e}
function qd(a,b,c,d){cd(a);(c=rd(a,c))&&c!==b&&null!=d&&(a.i&&c in a.i&&(a.i[c]=void 0),C(a,c));return C(a,b,d)}
function rd(a,b){for(var c=0,d=0;d<b.length;d++){var e=b[d];null!=od(a,e)&&(0!==c&&C(a,c,void 0,!1,!0),c=e)}return c}
function sd(a,b,c,d,e){e=void 0===e?!1:e;var f=e;if(-1===c)d=null;else{a.i||(a.i={});var g=a.i[c];if(g)d=g;else{var h=od(a,c,f);b=gd(h,b,d);void 0==b?d=g:(d&&b.A!==h&&C(a,c,b.A,f,!0),a.i[c]=b,Vc(a.A)&&Zc(b.A),d=b)}}if(null==d)return d;Vc(d.A)&&!Vc(a.A)&&(d=d.mb(kc),C(a,c,d.A,e),a.i[c]=d);return d}
function td(a,b,c,d){a.i||(a.i={});var e=Vc(a.A),f=a.i[c];if(!f){d=pd(a,c,!0,d);f=[];e=e||Vc(d);for(var g=0;g<d.length;g++){var h=gd(d[g],b);void 0!==h&&(f.push(h),e&&Zc(h.A))}e&&(Zc(f),Object.freeze(f));a.i[c]=f}return f}
function D(a,b,c){cd(a);a.i||(a.i={});var d=null!=c?c.A:c;a.i[b]=c;return C(a,b,d)}
function ud(a,b,c,d){cd(a);a.i||(a.i={});var e=null!=d?d.A:d;a.i[b]=d;qd(a,b,c,e)}
function vd(a,b,c,d){cd(a);var e=td(a,c,b);c=null!=d?d:new c;a=pd(a,b);e.push(c);a.push(c.A)}
function wd(a,b){a=od(a,b);return null==a?"":a}
;function xd(a,b,c){a||(a=yd);yd=null;var d=this.constructor.j;a||(a=d?[d]:[]);this.ja=(d?0:-1)-(this.constructor.i||0);this.i=void 0;this.A=a;a:{d=this.A.length;a=d-1;if(d&&(d=this.A[a],$c(d))){this.l=a-this.ja;this.j=d;break a}void 0!==b&&-1<b?(this.l=Math.max(b,a+1-this.ja),this.j=void 0):this.l=Number.MAX_VALUE}if(c)for(b=0;b<c.length;b++)if(a=c[b],a<this.l)a+=this.ja,(d=this.A[a])?Array.isArray(d)&&Uc(d):this.A[a]=bd;else{d=nd(this);var e=d[a];e?Array.isArray(e)&&Uc(e):d[a]=bd}}
xd.prototype.toJSON=function(){var a=this.A;return ad?a:id(a,md)};
xd.prototype.clone=function(){var a=id(this.A);yd=a;a=new this.constructor(a);yd=null;zd(a,this);return a};
xd.prototype.isMutable=function(a){lc(a);return!Vc(this.A)};
xd.prototype.toString=function(){return this.A.toString()};
function Ad(a,b){return hd(b)}
function zd(a,b){b.xa&&(a.xa=b.xa.slice());var c=b.i;if(c){b=b.j;for(var d in c){var e=c[d];if(e){var f=!(!b||!b[d]),g=+d;if(Array.isArray(e)){if(e.length){var h=a,k=f;k=void 0===k?!1:k;f=td(h,e[0].constructor,g,k);var m=Vc(h.A);g=od(h,g,k);for(h=0;h<f.length;h++)(k=f[h])&&Vc(k.A)&&!m&&(f[h]=f[h].mb(kc),g[h]=f[h].A);for(m=0;m<Math.min(f.length,e.length);m++)zd(f[m],e[m])}}else(f=sd(a,e.constructor,g,void 0,f))&&zd(f,e)}}}}
var yd;function Bd(){xd.apply(this,arguments)}
r(Bd,xd);Bd.prototype.mb=function(){return this};
if(dd){var Cd={};Object.defineProperties(Bd,(Cd[Symbol.hasInstance]=ed(function(){throw Error("Cannot perform instanceof checks for MutableMessage");}),Cd))};function Dd(a,b,c,d,e,f){if(a=a.i&&a.i[c])if(Array.isArray(a)){e=f.Ya?Uc(a.slice()):a;cd(b);if(e){f=Uc([]);for(d=0;d<e.length;d++)f[d]=e[d].A;b.i||(b.i={});b.i[c]=e}else b.i&&(b.i[c]=void 0),f=bd;C(b,c,f)}else D(b,c,a);else Mc&&d instanceof Uint8Array?e=d.length?new Pc(new Uint8Array(d)):Oc||(Oc=new Pc(null)):(Array.isArray(d)&&(e?Zc(d):Tc(d)&&f.Ya&&(d=d.slice())),e=d),C(b,c,e)}
;function H(){Bd.apply(this,arguments)}
r(H,Bd);H.prototype.mb=function(a){lc(a);if(Vc(this.A)){a={Ya:!0};var b=Vc(this.A);if(b&&!a.Ya)throw Error("copyRepeatedFields must be true for frozen messages");var c=new this.constructor;this.xa&&(c.xa=this.xa.slice());for(var d=this.A,e=0;e<d.length;e++){var f=d[e];if(e===d.length-1&&$c(f))for(h in f){var g=+h;Number.isNaN(g)?nd(c)[h]=f[h]:Dd(this,c,g,f[h],b,a)}else Dd(this,c,e-this.ja,f,b,a)}var h=c}else h=this;return h};
if(dd){var Ed={};Object.defineProperties(H,(Ed[Symbol.hasInstance]=ed(Object[Symbol.hasInstance]),Ed))};function Fd(){var a=this;this.promise=new Promise(function(b,c){a.resolve=b;a.reject=c})}
;function Gd(a){this.j=!1;var b=a.program;a=a.globalName;var c=new Fd;this.l=c.promise;this.m=q((0,y[a].a)(b,function(d,e){Promise.resolve().then(function(){c.resolve({Rb:d,Ac:e})})},!0)).next().value;
this.zc=c.promise.then(function(){})}
Gd.prototype.snapshot=function(a){if(this.j)throw Error("Already disposed");return this.l.then(function(b){var c=b.Rb;return new Promise(function(d){c(function(e){d(e)},[a.sb,
a.Bc])})})};
Gd.prototype.dispose=function(){this.j=!0;this.l.then(function(a){(a=a.Ac)&&a()})};
Gd.prototype.i=function(){return this.j};var Hd=window;Bb("csi.gstatic.com");Bb("googleads.g.doubleclick.net");Bb("partner.googleadservices.com");Bb("pubads.g.doubleclick.net");Bb("securepubads.g.doubleclick.net");Bb("tpc.googlesyndication.com");/*

 SPDX-License-Identifier: Apache-2.0
*/
var Id={};function Jd(){}
function Kd(a){this.i=a}
r(Kd,Jd);Kd.prototype.toString=function(){return this.i};
var Ld=new Kd("about:invalid#zTSz",Id);function Md(a){if(a instanceof Jd)if(a instanceof Kd)a=a.i;else throw Error("");else a=Lb(a);return a}
;function Nd(a,b){a.src=Gb(b);var c,d;(c=(b=null==(d=(c=(a.ownerDocument&&a.ownerDocument.defaultView||window).document).querySelector)?void 0:d.call(c,"script[nonce]"))?b.nonce||b.getAttribute("nonce")||"":"")&&a.setAttribute("nonce",c)}
;function Od(a,b){this.x=void 0!==a?a:0;this.y=void 0!==b?b:0}
l=Od.prototype;l.clone=function(){return new Od(this.x,this.y)};
l.equals=function(a){return a instanceof Od&&(this==a?!0:this&&a?this.x==a.x&&this.y==a.y:!1)};
l.ceil=function(){this.x=Math.ceil(this.x);this.y=Math.ceil(this.y);return this};
l.floor=function(){this.x=Math.floor(this.x);this.y=Math.floor(this.y);return this};
l.round=function(){this.x=Math.round(this.x);this.y=Math.round(this.y);return this};
l.scale=function(a,b){this.x*=a;this.y*="number"===typeof b?b:a;return this};function Pd(a,b){this.width=a;this.height=b}
l=Pd.prototype;l.clone=function(){return new Pd(this.width,this.height)};
l.aspectRatio=function(){return this.width/this.height};
l.isEmpty=function(){return!(this.width*this.height)};
l.ceil=function(){this.width=Math.ceil(this.width);this.height=Math.ceil(this.height);return this};
l.floor=function(){this.width=Math.floor(this.width);this.height=Math.floor(this.height);return this};
l.round=function(){this.width=Math.round(this.width);this.height=Math.round(this.height);return this};
l.scale=function(a,b){this.width*=a;this.height*="number"===typeof b?b:a;return this};function Qd(a){var b=document;return"string"===typeof a?b.getElementById(a):a}
function Rd(a){var b=document;a=String(a);"application/xhtml+xml"===b.contentType&&(a=a.toLowerCase());return b.createElement(a)}
function Sd(a,b){for(var c=0;a;){if(b(a))return a;a=a.parentNode;c++}return null}
;function Td(a){var b=Ud;if(b)for(var c in b)Object.prototype.hasOwnProperty.call(b,c)&&a(b[c],c,b)}
function Vd(){var a=[];Td(function(b){a.push(b)});
return a}
var Ud={Sc:"allow-forms",Tc:"allow-modals",Uc:"allow-orientation-lock",Vc:"allow-pointer-lock",Wc:"allow-popups",Xc:"allow-popups-to-escape-sandbox",Yc:"allow-presentation",Zc:"allow-same-origin",bd:"allow-scripts",cd:"allow-top-navigation",dd:"allow-top-navigation-by-user-activation"},Wd=bb(function(){return Vd()});
function Xd(){var a=ae(),b={};db(Wd(),function(c){a.sandbox&&a.sandbox.supports&&a.sandbox.supports(c)&&(b[c]=!0)});
return b}
function ae(){var a=void 0===a?document:a;return a.createElement("iframe")}
;function be(a){this.isValid=a}
function ce(a){return new be(function(b){return b.substr(0,a.length+1).toLowerCase()===a+":"})}
var de=[ce("data"),ce("http"),ce("https"),ce("mailto"),ce("ftp"),new be(function(a){return/^[^:]*([/?#]|$)/.test(a)})];function ee(a){"number"==typeof a&&(a=Math.round(a)+"px");return a}
;var fe=(new Date).getTime();function ge(a){if(!a)return"";if(/^about:(?:blank|srcdoc)$/.test(a))return window.origin||"";a=a.split("#")[0].split("?")[0];a=a.toLowerCase();0==a.indexOf("//")&&(a=window.location.protocol+a);/^[\w\-]*:\/\//.test(a)||(a=window.location.href);var b=a.substring(a.indexOf("://")+3),c=b.indexOf("/");-1!=c&&(b=b.substring(0,c));c=a.substring(0,a.indexOf("://"));if(!c)throw Error("URI is missing protocol: "+a);if("http"!==c&&"https"!==c&&"chrome-extension"!==c&&"moz-extension"!==c&&"file"!==c&&"android-app"!==
c&&"chrome-search"!==c&&"chrome-untrusted"!==c&&"chrome"!==c&&"app"!==c&&"devtools"!==c)throw Error("Invalid URI scheme in origin: "+c);a="";var d=b.indexOf(":");if(-1!=d){var e=b.substring(d+1);b=b.substring(0,d);if("http"===c&&"80"!==e||"https"===c&&"443"!==e)a=":"+e}return c+"://"+b+a}
;var he="client_dev_mss_url client_dev_regex_map client_dev_root_url client_rollout_override expflag forcedCapability jsfeat jsmode mods".split(" ");fa(he);function ie(){function a(){e[0]=1732584193;e[1]=4023233417;e[2]=2562383102;e[3]=271733878;e[4]=3285377520;p=m=0}
function b(u){for(var x=g,v=0;64>v;v+=4)x[v/4]=u[v]<<24|u[v+1]<<16|u[v+2]<<8|u[v+3];for(v=16;80>v;v++)u=x[v-3]^x[v-8]^x[v-14]^x[v-16],x[v]=(u<<1|u>>>31)&4294967295;u=e[0];var E=e[1],G=e[2],K=e[3],N=e[4];for(v=0;80>v;v++){if(40>v)if(20>v){var O=K^E&(G^K);var S=1518500249}else O=E^G^K,S=1859775393;else 60>v?(O=E&G|K&(E|G),S=2400959708):(O=E^G^K,S=3395469782);O=((u<<5|u>>>27)&4294967295)+O+N+S+x[v]&4294967295;N=K;K=G;G=(E<<30|E>>>2)&4294967295;E=u;u=O}e[0]=e[0]+u&4294967295;e[1]=e[1]+E&4294967295;e[2]=
e[2]+G&4294967295;e[3]=e[3]+K&4294967295;e[4]=e[4]+N&4294967295}
function c(u,x){if("string"===typeof u){u=unescape(encodeURIComponent(u));for(var v=[],E=0,G=u.length;E<G;++E)v.push(u.charCodeAt(E));u=v}x||(x=u.length);v=0;if(0==m)for(;v+64<x;)b(u.slice(v,v+64)),v+=64,p+=64;for(;v<x;)if(f[m++]=u[v++],p++,64==m)for(m=0,b(f);v+64<x;)b(u.slice(v,v+64)),v+=64,p+=64}
function d(){var u=[],x=8*p;56>m?c(h,56-m):c(h,64-(m-56));for(var v=63;56<=v;v--)f[v]=x&255,x>>>=8;b(f);for(v=x=0;5>v;v++)for(var E=24;0<=E;E-=8)u[x++]=e[v]>>E&255;return u}
for(var e=[],f=[],g=[],h=[128],k=1;64>k;++k)h[k]=0;var m,p;a();return{reset:a,update:c,digest:d,Vb:function(){for(var u=d(),x="",v=0;v<u.length;v++)x+="0123456789ABCDEF".charAt(Math.floor(u[v]/16))+"0123456789ABCDEF".charAt(u[v]%16);return x}}}
;function je(a,b,c){var d=String(y.location.href);return d&&a&&b?[b,ke(ge(d),a,c||null)].join(" "):null}
function ke(a,b,c){var d=[],e=[];if(1==(Array.isArray(c)?2:1))return e=[b,a],db(d,function(h){e.push(h)}),le(e.join(" "));
var f=[],g=[];db(c,function(h){g.push(h.key);f.push(h.value)});
c=Math.floor((new Date).getTime()/1E3);e=0==f.length?[c,b,a]:[f.join(":"),c,b,a];db(d,function(h){e.push(h)});
a=le(e.join(" "));a=[c,a];0==g.length||a.push(g.join(""));return a.join("_")}
function le(a){var b=ie();b.update(a);return b.Vb().toLowerCase()}
;var me={};function ne(a){this.i=a||{cookie:""}}
l=ne.prototype;l.isEnabled=function(){if(!y.navigator.cookieEnabled)return!1;if(!this.isEmpty())return!0;this.set("TESTCOOKIESENABLED","1",{Qa:60});if("1"!==this.get("TESTCOOKIESENABLED"))return!1;this.remove("TESTCOOKIESENABLED");return!0};
l.set=function(a,b,c){var d=!1;if("object"===typeof c){var e=c.Cp;d=c.secure||!1;var f=c.domain||void 0;var g=c.path||void 0;var h=c.Qa}if(/[;=\s]/.test(a))throw Error('Invalid cookie name "'+a+'"');if(/[;\r\n]/.test(b))throw Error('Invalid cookie value "'+b+'"');void 0===h&&(h=-1);c=f?";domain="+f:"";g=g?";path="+g:"";d=d?";secure":"";h=0>h?"":0==h?";expires="+(new Date(1970,1,1)).toUTCString():";expires="+(new Date(Date.now()+1E3*h)).toUTCString();this.i.cookie=a+"="+b+c+g+h+d+(null!=e?";samesite="+
e:"")};
l.get=function(a,b){for(var c=a+"=",d=(this.i.cookie||"").split(";"),e=0,f;e<d.length;e++){f=Ib(d[e]);if(0==f.lastIndexOf(c,0))return f.slice(c.length);if(f==a)return""}return b};
l.remove=function(a,b,c){var d=void 0!==this.get(a);this.set(a,"",{Qa:0,path:b,domain:c});return d};
l.bb=function(){return oe(this).keys};
l.isEmpty=function(){return!this.i.cookie};
l.clear=function(){for(var a=oe(this).keys,b=a.length-1;0<=b;b--)this.remove(a[b])};
function oe(a){a=(a.i.cookie||"").split(";");for(var b=[],c=[],d,e,f=0;f<a.length;f++)e=Ib(a[f]),d=e.indexOf("="),-1==d?(b.push(""),c.push(e)):(b.push(e.substring(0,d)),c.push(e.substring(d+1)));return{keys:b,values:c}}
var pe=new ne("undefined"==typeof document?null:document);function qe(a){return!!me.FPA_SAMESITE_PHASE2_MOD||!(void 0===a||!a)}
function re(a){a=void 0===a?!1:a;var b=y.__SAPISID||y.__APISID||y.__3PSAPISID||y.__OVERRIDE_SID;qe(a)&&(b=b||y.__1PSAPISID);if(b)return!0;var c=new ne(document);b=c.get("SAPISID")||c.get("APISID")||c.get("__Secure-3PAPISID")||c.get("SID");qe(a)&&(b=b||c.get("__Secure-1PAPISID"));return!!b}
function se(a,b,c,d){(a=y[a])||(a=(new ne(document)).get(b));return a?je(a,c,d):null}
function te(a){var b=void 0===b?!1:b;var c=ge(String(y.location.href)),d=[];if(re(b)){c=0==c.indexOf("https:")||0==c.indexOf("chrome-extension:")||0==c.indexOf("moz-extension:");var e=c?y.__SAPISID:y.__APISID;e||(e=new ne(document),e=e.get(c?"SAPISID":"APISID")||e.get("__Secure-3PAPISID"));(e=e?je(e,c?"SAPISIDHASH":"APISIDHASH",a):null)&&d.push(e);c&&qe(b)&&((b=se("__1PSAPISID","__Secure-1PAPISID","SAPISID1PHASH",a))&&d.push(b),(a=se("__3PSAPISID","__Secure-3PAPISID","SAPISID3PHASH",a))&&d.push(a))}return 0==
d.length?null:d.join(" ")}
;function ue(a){a&&"function"==typeof a.dispose&&a.dispose()}
;function ve(a){for(var b=0,c=arguments.length;b<c;++b){var d=arguments[b];Na(d)?ve.apply(null,d):ue(d)}}
;function I(){this.F=this.F;this.s=this.s}
I.prototype.F=!1;I.prototype.i=function(){return this.F};
I.prototype.dispose=function(){this.F||(this.F=!0,this.I())};
function we(a,b){a.F?b():(a.s||(a.s=[]),a.s.push(b))}
I.prototype.I=function(){if(this.s)for(;this.s.length;)this.s.shift()()};function xe(a,b){this.type=a;this.i=this.target=b;this.defaultPrevented=this.l=!1}
xe.prototype.stopPropagation=function(){this.l=!0};
xe.prototype.preventDefault=function(){this.defaultPrevented=!0};function ye(a){var b=A("window.location.href");null==a&&(a='Unknown Error of type "null/undefined"');if("string"===typeof a)return{message:a,name:"Unknown error",lineNumber:"Not available",fileName:b,stack:"Not available"};var c=!1;try{var d=a.lineNumber||a.line||"Not available"}catch(g){d="Not available",c=!0}try{var e=a.fileName||a.filename||a.sourceURL||y.$googDebugFname||b}catch(g){e="Not available",c=!0}b=ze(a);if(!(!c&&a.lineNumber&&a.fileName&&a.stack&&a.message&&a.name)){c=a.message;if(null==
c){if(a.constructor&&a.constructor instanceof Function){if(a.constructor.name)c=a.constructor.name;else if(c=a.constructor,Ae[c])c=Ae[c];else{c=String(c);if(!Ae[c]){var f=/function\s+([^\(]+)/m.exec(c);Ae[c]=f?f[1]:"[Anonymous]"}c=Ae[c]}c='Unknown Error of type "'+c+'"'}else c="Unknown Error of unknown type";"function"===typeof a.toString&&Object.prototype.toString!==a.toString&&(c+=": "+a.toString())}return{message:c,name:a.name||"UnknownError",lineNumber:d,fileName:e,stack:b||"Not available"}}a.stack=
b;return{message:a.message,name:a.name,lineNumber:a.lineNumber,fileName:a.fileName,stack:a.stack}}
function ze(a,b){b||(b={});b[Be(a)]=!0;var c=a.stack||"";(a=a.Sb)&&!b[Be(a)]&&(c+="\nCaused by: ",a.stack&&0==a.stack.indexOf(a.toString())||(c+="string"===typeof a?a:a.message+"\n"),c+=ze(a,b));return c}
function Be(a){var b="";"function"===typeof a.toString&&(b=""+a);return b+a.stack}
var Ae={};var Ce=function(){if(!y.addEventListener||!Object.defineProperty)return!1;var a=!1,b=Object.defineProperty({},"passive",{get:function(){a=!0}});
try{y.addEventListener("test",function(){},b),y.removeEventListener("test",function(){},b)}catch(c){}return a}();function De(a,b){xe.call(this,a?a.type:"");this.relatedTarget=this.i=this.target=null;this.button=this.screenY=this.screenX=this.clientY=this.clientX=0;this.key="";this.charCode=this.keyCode=0;this.metaKey=this.shiftKey=this.altKey=this.ctrlKey=!1;this.state=null;this.pointerId=0;this.pointerType="";this.j=null;a&&this.init(a,b)}
Xa(De,xe);var Ee={2:"touch",3:"pen",4:"mouse"};
De.prototype.init=function(a,b){var c=this.type=a.type,d=a.changedTouches&&a.changedTouches.length?a.changedTouches[0]:null;this.target=a.target||a.srcElement;this.i=b;if(b=a.relatedTarget){if(uc){a:{try{qc(b.nodeName);var e=!0;break a}catch(f){}e=!1}e||(b=null)}}else"mouseover"==c?b=a.fromElement:"mouseout"==c&&(b=a.toElement);this.relatedTarget=b;d?(this.clientX=void 0!==d.clientX?d.clientX:d.pageX,this.clientY=void 0!==d.clientY?d.clientY:d.pageY,this.screenX=d.screenX||0,this.screenY=d.screenY||
0):(this.clientX=void 0!==a.clientX?a.clientX:a.pageX,this.clientY=void 0!==a.clientY?a.clientY:a.pageY,this.screenX=a.screenX||0,this.screenY=a.screenY||0);this.button=a.button;this.keyCode=a.keyCode||0;this.key=a.key||"";this.charCode=a.charCode||("keypress"==c?a.keyCode:0);this.ctrlKey=a.ctrlKey;this.altKey=a.altKey;this.shiftKey=a.shiftKey;this.metaKey=a.metaKey;this.pointerId=a.pointerId||0;this.pointerType="string"===typeof a.pointerType?a.pointerType:Ee[a.pointerType]||"";this.state=a.state;
this.j=a;a.defaultPrevented&&De.Y.preventDefault.call(this)};
De.prototype.stopPropagation=function(){De.Y.stopPropagation.call(this);this.j.stopPropagation?this.j.stopPropagation():this.j.cancelBubble=!0};
De.prototype.preventDefault=function(){De.Y.preventDefault.call(this);var a=this.j;a.preventDefault?a.preventDefault():a.returnValue=!1};var Fe="closure_listenable_"+(1E6*Math.random()|0);var Ge=0;function He(a,b,c,d,e){this.listener=a;this.proxy=null;this.src=b;this.type=c;this.capture=!!d;this.Na=e;this.key=++Ge;this.za=this.Ja=!1}
function Ie(a){a.za=!0;a.listener=null;a.proxy=null;a.src=null;a.Na=null}
;function Je(a){this.src=a;this.listeners={};this.i=0}
Je.prototype.add=function(a,b,c,d,e){var f=a.toString();a=this.listeners[f];a||(a=this.listeners[f]=[],this.i++);var g=Ke(a,b,d,e);-1<g?(b=a[g],c||(b.Ja=!1)):(b=new He(b,this.src,f,!!d,e),b.Ja=c,a.push(b));return b};
Je.prototype.remove=function(a,b,c,d){a=a.toString();if(!(a in this.listeners))return!1;var e=this.listeners[a];b=Ke(e,b,c,d);return-1<b?(Ie(e[b]),Array.prototype.splice.call(e,b,1),0==e.length&&(delete this.listeners[a],this.i--),!0):!1};
function Le(a,b){var c=b.type;c in a.listeners&&ib(a.listeners[c],b)&&(Ie(b),0==a.listeners[c].length&&(delete a.listeners[c],a.i--))}
function Ke(a,b,c,d){for(var e=0;e<a.length;++e){var f=a[e];if(!f.za&&f.listener==b&&f.capture==!!c&&f.Na==d)return e}return-1}
;var Me="closure_lm_"+(1E6*Math.random()|0),Ne={},Oe=0;function Pe(a,b,c,d,e){if(d&&d.once)Qe(a,b,c,d,e);else if(Array.isArray(b))for(var f=0;f<b.length;f++)Pe(a,b[f],c,d,e);else c=Re(c),a&&a[Fe]?a.U(b,c,Pa(d)?!!d.capture:!!d,e):Se(a,b,c,!1,d,e)}
function Se(a,b,c,d,e,f){if(!b)throw Error("Invalid event type");var g=Pa(e)?!!e.capture:!!e,h=Te(a);h||(a[Me]=h=new Je(a));c=h.add(b,c,d,g,f);if(!c.proxy){d=Ue();c.proxy=d;d.src=a;d.listener=c;if(a.addEventListener)Ce||(e=g),void 0===e&&(e=!1),a.addEventListener(b.toString(),d,e);else if(a.attachEvent)a.attachEvent(Ve(b.toString()),d);else if(a.addListener&&a.removeListener)a.addListener(d);else throw Error("addEventListener and attachEvent are unavailable.");Oe++}}
function Ue(){function a(c){return b.call(a.src,a.listener,c)}
var b=We;return a}
function Qe(a,b,c,d,e){if(Array.isArray(b))for(var f=0;f<b.length;f++)Qe(a,b[f],c,d,e);else c=Re(c),a&&a[Fe]?a.m.add(String(b),c,!0,Pa(d)?!!d.capture:!!d,e):Se(a,b,c,!0,d,e)}
function Xe(a,b,c,d,e){if(Array.isArray(b))for(var f=0;f<b.length;f++)Xe(a,b[f],c,d,e);else(d=Pa(d)?!!d.capture:!!d,c=Re(c),a&&a[Fe])?a.m.remove(String(b),c,d,e):a&&(a=Te(a))&&(b=a.listeners[b.toString()],a=-1,b&&(a=Ke(b,c,d,e)),(c=-1<a?b[a]:null)&&Ye(c))}
function Ye(a){if("number"!==typeof a&&a&&!a.za){var b=a.src;if(b&&b[Fe])Le(b.m,a);else{var c=a.type,d=a.proxy;b.removeEventListener?b.removeEventListener(c,d,a.capture):b.detachEvent?b.detachEvent(Ve(c),d):b.addListener&&b.removeListener&&b.removeListener(d);Oe--;(c=Te(b))?(Le(c,a),0==c.i&&(c.src=null,b[Me]=null)):Ie(a)}}}
function Ve(a){return a in Ne?Ne[a]:Ne[a]="on"+a}
function We(a,b){if(a.za)a=!0;else{b=new De(b,this);var c=a.listener,d=a.Na||a.src;a.Ja&&Ye(a);a=c.call(d,b)}return a}
function Te(a){a=a[Me];return a instanceof Je?a:null}
var Ze="__closure_events_fn_"+(1E9*Math.random()>>>0);function Re(a){if("function"===typeof a)return a;a[Ze]||(a[Ze]=function(b){return a.handleEvent(b)});
return a[Ze]}
;function $e(){I.call(this);this.m=new Je(this);this.W=this;this.L=null}
Xa($e,I);$e.prototype[Fe]=!0;$e.prototype.addEventListener=function(a,b,c,d){Pe(this,a,b,c,d)};
$e.prototype.removeEventListener=function(a,b,c,d){Xe(this,a,b,c,d)};
function af(a,b){var c=a.L;if(c){var d=[];for(var e=1;c;c=c.L)d.push(c),++e}a=a.W;c=b.type||b;"string"===typeof b?b=new xe(b,a):b instanceof xe?b.target=b.target||a:(e=b,b=new xe(c,a),wb(b,e));e=!0;if(d)for(var f=d.length-1;!b.l&&0<=f;f--){var g=b.i=d[f];e=bf(g,c,!0,b)&&e}b.l||(g=b.i=a,e=bf(g,c,!0,b)&&e,b.l||(e=bf(g,c,!1,b)&&e));if(d)for(f=0;!b.l&&f<d.length;f++)g=b.i=d[f],e=bf(g,c,!1,b)&&e}
$e.prototype.I=function(){$e.Y.I.call(this);if(this.m){var a=this.m,b=0,c;for(c in a.listeners){for(var d=a.listeners[c],e=0;e<d.length;e++)++b,Ie(d[e]);delete a.listeners[c];a.i--}}this.L=null};
$e.prototype.U=function(a,b,c,d){return this.m.add(String(a),b,!1,c,d)};
function bf(a,b,c,d){b=a.m.listeners[String(b)];if(!b)return!0;b=b.concat();for(var e=!0,f=0;f<b.length;++f){var g=b[f];if(g&&!g.za&&g.capture==c){var h=g.listener,k=g.Na||g.src;g.Ja&&Le(a.m,g);e=!1!==h.call(k,d)&&e}}return e&&!d.defaultPrevented}
;function cf(a){$e.call(this);var b=this;this.B=this.l=0;this.T=null!=a?a:{M:function(e,f){return setTimeout(e,f)},
S:function(e){clearTimeout(e)}};
var c,d;this.j=null!=(d=null==(c=window.navigator)?void 0:c.onLine)?d:!0;this.o=function(){return w(function(e){return t(e,df(b),0)})};
window.addEventListener("offline",this.o);window.addEventListener("online",this.o);this.B||ef(this)}
r(cf,$e);function ff(){var a=gf;cf.i||(cf.i=new cf(a));return cf.i}
cf.prototype.dispose=function(){window.removeEventListener("offline",this.o);window.removeEventListener("online",this.o);this.T.S(this.B);delete cf.i};
cf.prototype.H=function(){return this.j};
function ef(a){a.B=a.T.M(function(){var b;return w(function(c){if(1==c.i)return a.j?(null==(b=window.navigator)?0:b.onLine)?c.u(3):t(c,df(a),3):t(c,df(a),3);ef(a);c.i=0})},3E4)}
function df(a,b){return a.v?a.v:a.v=new Promise(function(c){var d,e,f,g;return w(function(h){switch(h.i){case 1:return d=window.AbortController?new window.AbortController:void 0,f=null==(e=d)?void 0:e.signal,g=!1,ua(h,2,3),d&&(a.l=a.T.M(function(){d.abort()},b||2E4)),t(h,fetch("/generate_204",{method:"HEAD",
signal:f}),5);case 5:g=!0;case 3:za(h);a.v=void 0;a.l&&(a.T.S(a.l),a.l=0);g!==a.j&&(a.j=g,a.j?af(a,"networkstatus-online"):af(a,"networkstatus-offline"));c(g);Aa(h);break;case 2:ya(h),g=!1,h.u(3)}})})}
;var hf={Xg:"EMBEDDED_PLAYER_MODE_UNKNOWN",Ug:"EMBEDDED_PLAYER_MODE_DEFAULT",Wg:"EMBEDDED_PLAYER_MODE_PFP",Vg:"EMBEDDED_PLAYER_MODE_PFL"},jf={Vo:"WEB_DISPLAY_MODE_UNKNOWN",Ro:"WEB_DISPLAY_MODE_BROWSER",To:"WEB_DISPLAY_MODE_MINIMAL_UI",Uo:"WEB_DISPLAY_MODE_STANDALONE",So:"WEB_DISPLAY_MODE_FULLSCREEN"};function kf(){this.data_=[];this.i=-1}
kf.prototype.set=function(a,b){b=void 0===b?!0:b;0<=a&&52>a&&Number.isInteger(a)&&this.data_[a]!==b&&(this.data_[a]=b,this.i=-1)};
kf.prototype.get=function(a){return!!this.data_[a]};
function lf(a){-1===a.i&&(a.i=gb(a.data_,function(b,c,d){return c?b+Math.pow(2,d):b},0));
return a.i}
;function mf(a,b){this.l=a;this.m=b;this.j=0;this.i=null}
mf.prototype.get=function(){if(0<this.j){this.j--;var a=this.i;this.i=a.next;a.next=null}else a=this.l();return a};
function nf(a,b){a.m(b);100>a.j&&(a.j++,b.next=a.i,a.i=b)}
;var of;function pf(){var a=y.MessageChannel;"undefined"===typeof a&&"undefined"!==typeof window&&window.postMessage&&window.addEventListener&&!B("Presto")&&(a=function(){var e=Rd("IFRAME");e.style.display="none";document.documentElement.appendChild(e);var f=e.contentWindow;e=f.document;e.open();e.close();var g="callImmediate"+Math.random(),h="file:"==f.location.protocol?"*":f.location.protocol+"//"+f.location.host;e=Va(function(k){if(("*"==h||k.origin==h)&&k.data==g)this.port1.onmessage()},this);
f.addEventListener("message",e,!1);this.port1={};this.port2={postMessage:function(){f.postMessage(g,h)}}});
if("undefined"!==typeof a&&!B("Trident")&&!B("MSIE")){var b=new a,c={},d=c;b.port1.onmessage=function(){if(void 0!==c.next){c=c.next;var e=c.qb;c.qb=null;e()}};
return function(e){d.next={qb:e};d=d.next;b.port2.postMessage(0)}}return function(e){y.setTimeout(e,0)}}
;function qf(){this.j=this.i=null}
qf.prototype.add=function(a,b){var c=rf.get();c.set(a,b);this.j?this.j.next=c:this.i=c;this.j=c};
qf.prototype.remove=function(){var a=null;this.i&&(a=this.i,this.i=this.i.next,this.i||(this.j=null),a.next=null);return a};
var rf=new mf(function(){return new sf},function(a){return a.reset()});
function sf(){this.next=this.scope=this.i=null}
sf.prototype.set=function(a,b){this.i=a;this.scope=b;this.next=null};
sf.prototype.reset=function(){this.next=this.scope=this.i=null};function tf(a,b){uf||vf();wf||(uf(),wf=!0);xf.add(a,b)}
var uf;function vf(){if(y.Promise&&y.Promise.resolve){var a=y.Promise.resolve(void 0);uf=function(){a.then(yf)}}else uf=function(){var b=yf;
"function"!==typeof y.setImmediate||y.Window&&y.Window.prototype&&!B("Edge")&&y.Window.prototype.setImmediate==y.setImmediate?(of||(of=pf()),of(b)):y.setImmediate(b)}}
var wf=!1,xf=new qf;function yf(){for(var a;a=xf.remove();){try{a.i.call(a.scope)}catch(b){fd(b)}nf(rf,a)}wf=!1}
;function zf(a,b){this.i=a[y.Symbol.iterator]();this.j=b}
zf.prototype[Symbol.iterator]=function(){return this};
zf.prototype.next=function(){var a=this.i.next();return{value:a.done?void 0:this.j.call(void 0,a.value),done:a.done}};
function Af(a,b){return new zf(a,b)}
;function Bf(){this.blockSize=-1}
;function Cf(){this.blockSize=-1;this.blockSize=64;this.i=[];this.s=[];this.o=[];this.l=[];this.l[0]=128;for(var a=1;a<this.blockSize;++a)this.l[a]=0;this.m=this.j=0;this.reset()}
Xa(Cf,Bf);Cf.prototype.reset=function(){this.i[0]=1732584193;this.i[1]=4023233417;this.i[2]=2562383102;this.i[3]=271733878;this.i[4]=3285377520;this.m=this.j=0};
function Df(a,b,c){c||(c=0);var d=a.o;if("string"===typeof b)for(var e=0;16>e;e++)d[e]=b.charCodeAt(c)<<24|b.charCodeAt(c+1)<<16|b.charCodeAt(c+2)<<8|b.charCodeAt(c+3),c+=4;else for(e=0;16>e;e++)d[e]=b[c]<<24|b[c+1]<<16|b[c+2]<<8|b[c+3],c+=4;for(e=16;80>e;e++){var f=d[e-3]^d[e-8]^d[e-14]^d[e-16];d[e]=(f<<1|f>>>31)&4294967295}b=a.i[0];c=a.i[1];var g=a.i[2],h=a.i[3],k=a.i[4];for(e=0;80>e;e++){if(40>e)if(20>e){f=h^c&(g^h);var m=1518500249}else f=c^g^h,m=1859775393;else 60>e?(f=c&g|h&(c|g),m=2400959708):
(f=c^g^h,m=3395469782);f=(b<<5|b>>>27)+f+k+m+d[e]&4294967295;k=h;h=g;g=(c<<30|c>>>2)&4294967295;c=b;b=f}a.i[0]=a.i[0]+b&4294967295;a.i[1]=a.i[1]+c&4294967295;a.i[2]=a.i[2]+g&4294967295;a.i[3]=a.i[3]+h&4294967295;a.i[4]=a.i[4]+k&4294967295}
Cf.prototype.update=function(a,b){if(null!=a){void 0===b&&(b=a.length);for(var c=b-this.blockSize,d=0,e=this.s,f=this.j;d<b;){if(0==f)for(;d<=c;)Df(this,a,d),d+=this.blockSize;if("string"===typeof a)for(;d<b;){if(e[f]=a.charCodeAt(d),++f,++d,f==this.blockSize){Df(this,e);f=0;break}}else for(;d<b;)if(e[f]=a[d],++f,++d,f==this.blockSize){Df(this,e);f=0;break}}this.j=f;this.m+=b}};
Cf.prototype.digest=function(){var a=[],b=8*this.m;56>this.j?this.update(this.l,56-this.j):this.update(this.l,this.blockSize-(this.j-56));for(var c=this.blockSize-1;56<=c;c--)this.s[c]=b&255,b/=256;Df(this,this.s);for(c=b=0;5>c;c++)for(var d=24;0<=d;d-=8)a[b]=this.i[c]>>d&255,++b;return a};function Ef(a){return"string"==typeof a.className?a.className:a.getAttribute&&a.getAttribute("class")||""}
function Ff(a,b){"string"==typeof a.className?a.className=b:a.setAttribute&&a.setAttribute("class",b)}
function Gf(a,b){a.classList?b=a.classList.contains(b):(a=a.classList?a.classList:Ef(a).match(/\S+/g)||[],b=0<=cb(a,b));return b}
function Hf(){var a=document.body;a.classList?a.classList.remove("inverted-hdpi"):Gf(a,"inverted-hdpi")&&Ff(a,Array.prototype.filter.call(a.classList?a.classList:Ef(a).match(/\S+/g)||[],function(b){return"inverted-hdpi"!=b}).join(" "))}
;function If(){}
If.prototype.next=function(){return Jf};
var Jf={done:!0,value:void 0};function Kf(a){return{value:a,done:!1}}
If.prototype.X=function(){return this};function Lf(a){if(a instanceof Mf||a instanceof Nf||a instanceof Of)return a;if("function"==typeof a.next)return new Mf(function(){return a});
if("function"==typeof a[Symbol.iterator])return new Mf(function(){return a[Symbol.iterator]()});
if("function"==typeof a.X)return new Mf(function(){return a.X()});
throw Error("Not an iterator or iterable.");}
function Mf(a){this.j=a}
Mf.prototype.X=function(){return new Nf(this.j())};
Mf.prototype[Symbol.iterator]=function(){return new Of(this.j())};
Mf.prototype.i=function(){return new Of(this.j())};
function Nf(a){this.j=a}
r(Nf,If);Nf.prototype.next=function(){return this.j.next()};
Nf.prototype[Symbol.iterator]=function(){return new Of(this.j)};
Nf.prototype.i=function(){return new Of(this.j)};
function Of(a){Mf.call(this,function(){return a});
this.l=a}
r(Of,Mf);Of.prototype.next=function(){return this.l.next()};function Pf(a,b){this.j={};this.i=[];this.ha=this.size=0;var c=arguments.length;if(1<c){if(c%2)throw Error("Uneven number of arguments");for(var d=0;d<c;d+=2)this.set(arguments[d],arguments[d+1])}else if(a)if(a instanceof Pf)for(c=a.bb(),d=0;d<c.length;d++)this.set(c[d],a.get(c[d]));else for(d in a)this.set(d,a[d])}
l=Pf.prototype;l.bb=function(){Qf(this);return this.i.concat()};
l.has=function(a){return Tf(this.j,a)};
l.equals=function(a,b){if(this===a)return!0;if(this.size!=a.size)return!1;b=b||Uf;Qf(this);for(var c,d=0;c=this.i[d];d++)if(!b(this.get(c),a.get(c)))return!1;return!0};
function Uf(a,b){return a===b}
l.isEmpty=function(){return 0==this.size};
l.clear=function(){this.j={};this.ha=this.size=this.i.length=0};
l.remove=function(a){return this.delete(a)};
l.delete=function(a){return Tf(this.j,a)?(delete this.j[a],--this.size,this.ha++,this.i.length>2*this.size&&Qf(this),!0):!1};
function Qf(a){if(a.size!=a.i.length){for(var b=0,c=0;b<a.i.length;){var d=a.i[b];Tf(a.j,d)&&(a.i[c++]=d);b++}a.i.length=c}if(a.size!=a.i.length){var e={};for(c=b=0;b<a.i.length;)d=a.i[b],Tf(e,d)||(a.i[c++]=d,e[d]=1),b++;a.i.length=c}}
l.get=function(a,b){return Tf(this.j,a)?this.j[a]:b};
l.set=function(a,b){Tf(this.j,a)||(this.size+=1,this.i.push(a),this.ha++);this.j[a]=b};
l.forEach=function(a,b){for(var c=this.bb(),d=0;d<c.length;d++){var e=c[d],f=this.get(e);a.call(b,f,e,this)}};
l.clone=function(){return new Pf(this)};
l.keys=function(){return Lf(this.X(!0)).i()};
l.values=function(){return Lf(this.X(!1)).i()};
l.entries=function(){var a=this;return Af(this.keys(),function(b){return[b,a.get(b)]})};
l.X=function(a){Qf(this);var b=0,c=this.ha,d=this,e=new If;e.next=function(){if(c!=d.ha)throw Error("The map has changed since the iterator was created");if(b>=d.i.length)return Jf;var f=d.i[b++];return Kf(a?f:d.j[f])};
return e};
function Tf(a,b){return Object.prototype.hasOwnProperty.call(a,b)}
;function Vf(a){var b=[];Wf(new Xf,a,b);return b.join("")}
function Xf(){}
function Wf(a,b,c){if(null==b)c.push("null");else{if("object"==typeof b){if(Array.isArray(b)){var d=b;b=d.length;c.push("[");for(var e="",f=0;f<b;f++)c.push(e),Wf(a,d[f],c),e=",";c.push("]");return}if(b instanceof String||b instanceof Number||b instanceof Boolean)b=b.valueOf();else{c.push("{");e="";for(d in b)Object.prototype.hasOwnProperty.call(b,d)&&(f=b[d],"function"!=typeof f&&(c.push(e),Yf(d,c),c.push(":"),Wf(a,f,c),e=","));c.push("}");return}}switch(typeof b){case "string":Yf(b,c);break;case "number":c.push(isFinite(b)&&
!isNaN(b)?String(b):"null");break;case "boolean":c.push(String(b));break;case "function":c.push("null");break;default:throw Error("Unknown type: "+typeof b);}}}
var Zf={'"':'\\"',"\\":"\\\\","/":"\\/","\b":"\\b","\f":"\\f","\n":"\\n","\r":"\\r","\t":"\\t","\v":"\\u000b"},$f=/\uffff/.test("\uffff")?/[\\"\x00-\x1f\x7f-\uffff]/g:/[\\"\x00-\x1f\x7f-\xff]/g;function Yf(a,b){b.push('"',a.replace($f,function(c){var d=Zf[c];d||(d="\\u"+(c.charCodeAt(0)|65536).toString(16).slice(1),Zf[c]=d);return d}),'"')}
;function ag(a){this.i=0;this.F=void 0;this.m=this.j=this.l=null;this.s=this.o=!1;if(a!=ab)try{var b=this;a.call(void 0,function(c){bg(b,2,c)},function(c){bg(b,3,c)})}catch(c){bg(this,3,c)}}
function cg(){this.next=this.context=this.onRejected=this.j=this.i=null;this.l=!1}
cg.prototype.reset=function(){this.context=this.onRejected=this.j=this.i=null;this.l=!1};
var dg=new mf(function(){return new cg},function(a){a.reset()});
function eg(a,b,c){var d=dg.get();d.j=a;d.onRejected=b;d.context=c;return d}
function fg(a){return new ag(function(b,c){c(a)})}
ag.prototype.then=function(a,b,c){return gg(this,"function"===typeof a?a:null,"function"===typeof b?b:null,c)};
ag.prototype.$goog_Thenable=!0;function hg(a,b){return gg(a,null,b)}
ag.prototype.cancel=function(a){if(0==this.i){var b=new ig(a);tf(function(){jg(this,b)},this)}};
function jg(a,b){if(0==a.i)if(a.l){var c=a.l;if(c.j){for(var d=0,e=null,f=null,g=c.j;g&&(g.l||(d++,g.i==a&&(e=g),!(e&&1<d)));g=g.next)e||(f=g);e&&(0==c.i&&1==d?jg(c,b):(f?(d=f,d.next==c.m&&(c.m=d),d.next=d.next.next):kg(c),lg(c,e,3,b)))}a.l=null}else bg(a,3,b)}
function mg(a,b){a.j||2!=a.i&&3!=a.i||ng(a);a.m?a.m.next=b:a.j=b;a.m=b}
function gg(a,b,c,d){var e=eg(null,null,null);e.i=new ag(function(f,g){e.j=b?function(h){try{var k=b.call(d,h);f(k)}catch(m){g(m)}}:f;
e.onRejected=c?function(h){try{var k=c.call(d,h);void 0===k&&h instanceof ig?g(h):f(k)}catch(m){g(m)}}:g});
e.i.l=a;mg(a,e);return e.i}
ag.prototype.B=function(a){this.i=0;bg(this,2,a)};
ag.prototype.L=function(a){this.i=0;bg(this,3,a)};
function bg(a,b,c){if(0==a.i){a===c&&(b=3,c=new TypeError("Promise cannot resolve to itself"));a.i=1;a:{var d=c,e=a.B,f=a.L;if(d instanceof ag){mg(d,eg(e||ab,f||null,a));var g=!0}else{if(d)try{var h=!!d.$goog_Thenable}catch(m){h=!1}else h=!1;if(h)d.then(e,f,a),g=!0;else{if(Pa(d))try{var k=d.then;if("function"===typeof k){og(d,k,e,f,a);g=!0;break a}}catch(m){f.call(a,m);g=!0;break a}g=!1}}}g||(a.F=c,a.i=b,a.l=null,ng(a),3!=b||c instanceof ig||pg(a,c))}}
function og(a,b,c,d,e){function f(k){h||(h=!0,d.call(e,k))}
function g(k){h||(h=!0,c.call(e,k))}
var h=!1;try{b.call(a,g,f)}catch(k){f(k)}}
function ng(a){a.o||(a.o=!0,tf(a.v,a))}
function kg(a){var b=null;a.j&&(b=a.j,a.j=b.next,b.next=null);a.j||(a.m=null);return b}
ag.prototype.v=function(){for(var a;a=kg(this);)lg(this,a,this.i,this.F);this.o=!1};
function lg(a,b,c,d){if(3==c&&b.onRejected&&!b.l)for(;a&&a.s;a=a.l)a.s=!1;if(b.i)b.i.l=null,qg(b,c,d);else try{b.l?b.j.call(b.context):qg(b,c,d)}catch(e){rg.call(null,e)}nf(dg,b)}
function qg(a,b,c){2==b?a.j.call(a.context,c):a.onRejected&&a.onRejected.call(a.context,c)}
function pg(a,b){a.s=!0;tf(function(){a.s&&rg.call(null,b)})}
var rg=fd;function ig(a){Za.call(this,a)}
Xa(ig,Za);ig.prototype.name="cancel";function J(a){I.call(this);this.v=1;this.m=[];this.o=0;this.j=[];this.l={};this.B=!!a}
Xa(J,I);l=J.prototype;l.subscribe=function(a,b,c){var d=this.l[a];d||(d=this.l[a]=[]);var e=this.v;this.j[e]=a;this.j[e+1]=b;this.j[e+2]=c;this.v=e+3;d.push(e);return e};
function sg(a,b,c,d){if(b=a.l[b]){var e=a.j;(b=b.find(function(f){return e[f+1]==c&&e[f+2]==d}))&&a.ta(b)}}
l.ta=function(a){var b=this.j[a];if(b){var c=this.l[b];0!=this.o?(this.m.push(a),this.j[a+1]=function(){}):(c&&ib(c,a),delete this.j[a],delete this.j[a+1],delete this.j[a+2])}return!!b};
l.ia=function(a,b){var c=this.l[a];if(c){for(var d=Array(arguments.length-1),e=1,f=arguments.length;e<f;e++)d[e-1]=arguments[e];if(this.B)for(e=0;e<c.length;e++){var g=c[e];tg(this.j[g+1],this.j[g+2],d)}else{this.o++;try{for(e=0,f=c.length;e<f&&!this.i();e++)g=c[e],this.j[g+1].apply(this.j[g+2],d)}finally{if(this.o--,0<this.m.length&&0==this.o)for(;c=this.m.pop();)this.ta(c)}}return 0!=e}return!1};
function tg(a,b,c){tf(function(){a.apply(b,c)})}
l.clear=function(a){if(a){var b=this.l[a];b&&(b.forEach(this.ta,this),delete this.l[a])}else this.j.length=0,this.l={}};
l.I=function(){J.Y.I.call(this);this.clear();this.m.length=0};function ug(a){this.i=a}
ug.prototype.set=function(a,b){void 0===b?this.i.remove(a):this.i.set(a,Vf(b))};
ug.prototype.get=function(a){try{var b=this.i.get(a)}catch(c){return}if(null!==b)try{return JSON.parse(b)}catch(c){throw"Storage: Invalid value was encountered";}};
ug.prototype.remove=function(a){this.i.remove(a)};function vg(a){this.i=a}
Xa(vg,ug);function wg(a){this.data=a}
function xg(a){return void 0===a||a instanceof wg?a:new wg(a)}
vg.prototype.set=function(a,b){vg.Y.set.call(this,a,xg(b))};
vg.prototype.j=function(a){a=vg.Y.get.call(this,a);if(void 0===a||a instanceof Object)return a;throw"Storage: Invalid value was encountered";};
vg.prototype.get=function(a){if(a=this.j(a)){if(a=a.data,void 0===a)throw"Storage: Invalid value was encountered";}else a=void 0;return a};function yg(a){this.i=a}
Xa(yg,vg);yg.prototype.set=function(a,b,c){if(b=xg(b)){if(c){if(c<Date.now()){yg.prototype.remove.call(this,a);return}b.expiration=c}b.creation=Date.now()}yg.Y.set.call(this,a,b)};
yg.prototype.j=function(a){var b=yg.Y.j.call(this,a);if(b){var c=b.creation,d=b.expiration;if(d&&d<Date.now()||c&&c>Date.now())yg.prototype.remove.call(this,a);else return b}};function zg(){}
;function Ag(){}
Xa(Ag,zg);Ag.prototype[Symbol.iterator]=function(){return Lf(this.X(!0)).i()};
Ag.prototype.clear=function(){var a=Array.from(this);a=q(a);for(var b=a.next();!b.done;b=a.next())this.remove(b.value)};function Bg(a){this.i=a}
Xa(Bg,Ag);l=Bg.prototype;l.isAvailable=function(){if(!this.i)return!1;try{return this.i.setItem("__sak","1"),this.i.removeItem("__sak"),!0}catch(a){return!1}};
l.set=function(a,b){try{this.i.setItem(a,b)}catch(c){if(0==this.i.length)throw"Storage mechanism: Storage disabled";throw"Storage mechanism: Quota exceeded";}};
l.get=function(a){a=this.i.getItem(a);if("string"!==typeof a&&null!==a)throw"Storage mechanism: Invalid value was encountered";return a};
l.remove=function(a){this.i.removeItem(a)};
l.X=function(a){var b=0,c=this.i,d=new If;d.next=function(){if(b>=c.length)return Jf;var e=c.key(b++);if(a)return Kf(e);e=c.getItem(e);if("string"!==typeof e)throw"Storage mechanism: Invalid value was encountered";return Kf(e)};
return d};
l.clear=function(){this.i.clear()};
l.key=function(a){return this.i.key(a)};function Cg(){var a=null;try{a=window.localStorage||null}catch(b){}this.i=a}
Xa(Cg,Bg);function Dg(a,b){this.j=a;this.i=null;var c;if(c=sc)c=!(9<=Number(Fc));if(c){Eg||(Eg=new Pf);this.i=Eg.get(a);this.i||(b?this.i=document.getElementById(b):(this.i=document.createElement("userdata"),this.i.addBehavior("#default#userData"),document.body.appendChild(this.i)),Eg.set(a,this.i));try{this.i.load(this.j)}catch(d){this.i=null}}}
Xa(Dg,Ag);var Fg={".":".2E","!":".21","~":".7E","*":".2A","'":".27","(":".28",")":".29","%":"."},Eg=null;function Gg(a){return"_"+encodeURIComponent(a).replace(/[.!~*'()%]/g,function(b){return Fg[b]})}
l=Dg.prototype;l.isAvailable=function(){return!!this.i};
l.set=function(a,b){this.i.setAttribute(Gg(a),b);Hg(this)};
l.get=function(a){a=this.i.getAttribute(Gg(a));if("string"!==typeof a&&null!==a)throw"Storage mechanism: Invalid value was encountered";return a};
l.remove=function(a){this.i.removeAttribute(Gg(a));Hg(this)};
l.X=function(a){var b=0,c=this.i.XMLDocument.documentElement.attributes,d=new If;d.next=function(){if(b>=c.length)return Jf;var e=c[b++];if(a)return Kf(decodeURIComponent(e.nodeName.replace(/\./g,"%")).slice(1));e=e.nodeValue;if("string"!==typeof e)throw"Storage mechanism: Invalid value was encountered";return Kf(e)};
return d};
l.clear=function(){for(var a=this.i.XMLDocument.documentElement,b=a.attributes.length;0<b;b--)a.removeAttribute(a.attributes[b-1].nodeName);Hg(this)};
function Hg(a){try{a.i.save(a.j)}catch(b){throw"Storage mechanism: Quota exceeded";}}
;function Ig(a,b){this.j=a;this.i=b+"::"}
Xa(Ig,Ag);Ig.prototype.set=function(a,b){this.j.set(this.i+a,b)};
Ig.prototype.get=function(a){return this.j.get(this.i+a)};
Ig.prototype.remove=function(a){this.j.remove(this.i+a)};
Ig.prototype.X=function(a){var b=this.j[Symbol.iterator](),c=this,d=new If;d.next=function(){var e=b.next();if(e.done)return e;for(e=e.value;e.slice(0,c.i.length)!=c.i;){e=b.next();if(e.done)return e;e=e.value}return Kf(a?e.slice(c.i.length):c.j.get(e))};
return d};function Jg(a){H.call(this,a)}
r(Jg,H);Jg.prototype.getKey=function(){return od(this,1)};
Jg.prototype.getValue=function(){return od(this,2===rd(this,Kg)?2:-1)};
Jg.prototype.setValue=function(a){return qd(this,2,Kg,a)};
var Kg=[2,3,4,5,6];function Lg(a){H.call(this,a)}
r(Lg,H);function Mg(a){H.call(this,a)}
r(Mg,H);function Ng(a){H.call(this,a,-1,Og)}
r(Ng,H);Ng.prototype.getPlayerType=function(){return od(this,36)};
Ng.prototype.setHomeGroupInfo=function(a){return D(this,81,a)};
var Og=[9,66,24,32,86,100,101];function Pg(a){H.call(this,a,-1,Qg)}
r(Pg,H);var Qg=[15,26,28];function Rg(a){H.call(this,a)}
r(Rg,H);Rg.prototype.setToken=function(a){return C(this,2,a)};function Sg(a){H.call(this,a,-1,Tg)}
r(Sg,H);Sg.prototype.setSafetyMode=function(a){return C(this,5,a)};
var Tg=[12];function Ug(a){H.call(this,a,-1,Vg)}
r(Ug,H);var Vg=[12];function Wg(a){H.call(this,a,-1,Xg)}
r(Wg,H);function Yg(a){H.call(this,a)}
r(Yg,H);Yg.prototype.getKey=function(){return wd(this,1)};
Yg.prototype.getValue=function(){return wd(this,2)};
Yg.prototype.setValue=function(a){return C(this,2,a)};
var Xg=[4,5];function Zg(a){H.call(this,a)}
r(Zg,H);function $g(a){H.call(this,a)}
r($g,H);var ah=[2,3,4];function bh(a){H.call(this,a)}
r(bh,H);bh.prototype.getMessage=function(){return wd(this,1)};function ch(a){H.call(this,a)}
r(ch,H);function dh(a){H.call(this,a)}
r(dh,H);function eh(a){H.call(this,a,-1,fh)}
r(eh,H);var fh=[10,17];function gh(a){H.call(this,a)}
r(gh,H);function hh(a){H.call(this,a)}
r(hh,H);hh.prototype.P=function(a){C(this,1,a)};function ih(a){H.call(this,a)}
r(ih,H);function jh(a){H.call(this,a)}
r(jh,H);function kh(a){H.call(this,a)}
r(kh,H);function lh(a,b){D(a,1,b)}
kh.prototype.P=function(a){C(this,2,a)};
function mh(a){H.call(this,a)}
r(mh,H);function nh(a,b){D(a,1,b)}
;function oh(a){H.call(this,a,-1,ph)}
r(oh,H);oh.prototype.P=function(a){C(this,1,a)};
function qh(a,b){D(a,2,b)}
var ph=[3];function rh(a){H.call(this,a)}
r(rh,H);rh.prototype.P=function(a){C(this,1,a)};function sh(a){H.call(this,a)}
r(sh,H);sh.prototype.P=function(a){C(this,1,a)};function th(a){H.call(this,a)}
r(th,H);th.prototype.P=function(a){C(this,1,a)};function uh(a){H.call(this,a)}
r(uh,H);function vh(a){H.call(this,a)}
r(vh,H);function wh(a){H.call(this,a,-1,xh)}
r(wh,H);function yh(a,b){return C(a,1,b)}
wh.prototype.getPlayerType=function(){var a=od(this,7);return null==a?0:a};
wh.prototype.setVideoId=function(a){return C(this,19,a)};
function zh(a,b){return C(a,25,b)}
function Ah(a,b){vd(a,68,Bh,b)}
function Bh(a){H.call(this,a)}
r(Bh,H);Bh.prototype.getId=function(){return wd(this,2)};
var xh=[83,68];function Ch(a){H.call(this,a)}
r(Ch,H);function Dh(a){H.call(this,a)}
r(Dh,H);function Eh(a){H.call(this,a)}
r(Eh,H);function Fh(a){H.call(this,a,432)}
r(Fh,H);
var Gh=[23,24,11,6,7,5,2,3,20,21,28,32,37,229,241,45,59,225,288,72,73,78,208,156,202,215,74,76,79,80,111,85,91,97,100,102,105,119,126,127,136,146,157,158,159,163,164,168,176,222,383,177,178,179,411,184,188,189,190,191,193,194,195,196,198,199,200,201,203,204,205,206,258,259,260,261,209,226,227,232,233,234,240,247,248,251,254,255,270,278,291,293,300,304,308,309,310,311,313,314,319,321,323,324,328,330,331,332,337,338,340,344,348,350,351,352,353,354,355,356,357,358,361,363,364,368,369,370,373,374,375,
378,380,381,388,389,403,412,429,413,414,415,416,417,418,430,423,424,425,426,427,431,117];var Hh={Uh:0,Fh:1,Lh:2,Mh:4,Rh:8,Nh:16,Oh:32,Th:64,Sh:128,Hh:256,Jh:512,Qh:1024,Ih:2048,Kh:4096,Gh:8192,Ph:16384};function Ih(a){H.call(this,a)}
r(Ih,H);function Jh(a){H.call(this,a)}
r(Jh,H);Jh.prototype.setVideoId=function(a){return qd(this,1,Kh,a)};
Jh.prototype.getPlaylistId=function(){return od(this,2===rd(this,Kh)?2:-1)};
var Kh=[1,2];function Lh(a){H.call(this,a,-1,Mh)}
r(Lh,H);var Mh=[3];function Nh(a,b){1<b.length?a[b[0]]=b[1]:1===b.length&&Object.assign(a,b[0])}
;var Oh=y.window,Ph,Qh,Rh=(null==Oh?void 0:null==(Ph=Oh.yt)?void 0:Ph.config_)||(null==Oh?void 0:null==(Qh=Oh.ytcfg)?void 0:Qh.data_)||{};z("yt.config_",Rh);function Sh(){Nh(Rh,arguments)}
function L(a,b){return a in Rh?Rh[a]:b}
function Th(){var a=Rh.EXPERIMENT_FLAGS;return a?a.web_disable_gel_stp_ecatcher_killswitch:void 0}
;function M(a){a=Uh(a);return"string"===typeof a&&"false"===a?!1:!!a}
function Vh(a,b){a=Uh(a);return void 0===a&&void 0!==b?b:Number(a||0)}
function Wh(){return L("EXPERIMENTS_TOKEN","")}
function Uh(a){var b=L("EXPERIMENTS_FORCED_FLAGS",{});return void 0!==b[a]?b[a]:L("EXPERIMENT_FLAGS",{})[a]}
function Xh(){var a=[],b=L("EXPERIMENTS_FORCED_FLAGS",{});for(c in b)a.push({key:c,value:String(b[c])});var c=L("EXPERIMENT_FLAGS",{});for(var d in c)d.startsWith("force_")&&void 0===b[d]&&a.push({key:d,value:String(c[d])});return a}
;var Yh=[];function Zh(a){Yh.forEach(function(b){return b(a)})}
function $h(a){return a&&window.yterr?function(){try{return a.apply(this,arguments)}catch(b){ai(b)}}:a}
function ai(a,b,c,d){var e=A("yt.logging.errors.log");e?e(a,"ERROR",b,c,d):(e=L("ERRORS",[]),e.push([a,"ERROR",b,c,d]),Sh("ERRORS",e));Zh(a)}
function bi(a,b,c,d){var e=A("yt.logging.errors.log");e?e(a,"WARNING",b,c,d):(e=L("ERRORS",[]),e.push([a,"WARNING",b,c,d]),Sh("ERRORS",e))}
;function ci(){var a=di;A("yt.ads.biscotti.getId_")||z("yt.ads.biscotti.getId_",a)}
function ei(a){z("yt.ads.biscotti.lastId_",a)}
;var fi=/^[\w.]*$/,gi={q:!0,search_query:!0};function hi(a,b){b=a.split(b);for(var c={},d=0,e=b.length;d<e;d++){var f=b[d].split("=");if(1==f.length&&f[0]||2==f.length)try{var g=ii(f[0]||""),h=ii(f[1]||"");g in c?Array.isArray(c[g])?jb(c[g],h):c[g]=[c[g],h]:c[g]=h}catch(u){var k=u,m=f[0],p=String(hi);k.args=[{key:m,value:f[1],query:a,method:ji==p?"unchanged":p}];gi.hasOwnProperty(m)||bi(k)}}return c}
var ji=String(hi);function ki(a){var b=[];kb(a,function(c,d){var e=encodeURIComponent(String(d)),f;Array.isArray(c)?f=c:f=[c];db(f,function(g){""==g?b.push(e):b.push(e+"="+encodeURIComponent(String(g)))})});
return b.join("&")}
function li(a){"?"==a.charAt(0)&&(a=a.substr(1));return hi(a,"&")}
function mi(a){return-1!=a.indexOf("?")?(a=(a||"").split("#")[0],a=a.split("?",2),li(1<a.length?a[1]:a[0])):{}}
function ni(a,b,c){var d=a.split("#",2);a=d[0];d=1<d.length?"#"+d[1]:"";var e=a.split("?",2);a=e[0];e=li(e[1]||"");for(var f in b)!c&&null!==e&&f in e||(e[f]=b[f]);return fc(a,e)+d}
function oi(a){if(!b)var b=window.location.href;var c=ac(1,a),d=bc(a);c&&d?(a=a.match(Zb),b=b.match(Zb),a=a[3]==b[3]&&a[1]==b[1]&&a[4]==b[4]):a=d?bc(b)==d&&(Number(ac(4,b))||null)==(Number(ac(4,a))||null):!0;return a}
function ii(a){return a&&a.match(fi)?a:decodeURIComponent(a.replace(/\+/g," "))}
;function pi(a){var b=qi;a=void 0===a?A("yt.ads.biscotti.lastId_")||"":a;var c=Object,d=c.assign,e={};e.dt=fe;e.flash="0";a:{try{var f=b.i.top.location.href}catch(va){f=2;break a}f=f?f===b.j.location.href?0:1:2}e=(e.frm=f,e);try{e.u_tz=-(new Date).getTimezoneOffset();var g=void 0===g?Hd:g;try{var h=g.history.length}catch(va){h=0}e.u_his=h;var k;e.u_h=null==(k=Hd.screen)?void 0:k.height;var m;e.u_w=null==(m=Hd.screen)?void 0:m.width;var p;e.u_ah=null==(p=Hd.screen)?void 0:p.availHeight;var u;e.u_aw=
null==(u=Hd.screen)?void 0:u.availWidth;var x;e.u_cd=null==(x=Hd.screen)?void 0:x.colorDepth}catch(va){}h=b.i;try{var v=h.screenX;var E=h.screenY}catch(va){}try{var G=h.outerWidth;var K=h.outerHeight}catch(va){}try{var N=h.innerWidth;var O=h.innerHeight}catch(va){}try{var S=h.screenLeft;var ka=h.screenTop}catch(va){}try{N=h.innerWidth,O=h.innerHeight}catch(va){}try{var V=h.screen.availWidth;var W=h.screen.availTop}catch(va){}v=[S,ka,v,E,V,W,G,K,N,O];try{var Oa=(b.i.top||window).document,wa="CSS1Compat"==
Oa.compatMode?Oa.documentElement:Oa.body;var F=(new Pd(wa.clientWidth,wa.clientHeight)).round()}catch(va){F=new Pd(-12245933,-12245933)}Oa=F;F={};var Da=void 0===Da?y:Da;wa=new kf;Da.SVGElement&&Da.document.createElementNS&&wa.set(0);E=Xd();E["allow-top-navigation-by-user-activation"]&&wa.set(1);E["allow-popups-to-escape-sandbox"]&&wa.set(2);Da.crypto&&Da.crypto.subtle&&wa.set(3);Da.TextDecoder&&Da.TextEncoder&&wa.set(4);Da=lf(wa);F.bc=Da;F.bih=Oa.height;F.biw=Oa.width;F.brdim=v.join();b=b.j;b=(F.vis=
b.prerendering?3:{visible:1,hidden:2,prerender:3,preview:4,unloaded:5}[b.visibilityState||b.webkitVisibilityState||b.mozVisibilityState||""]||0,F.wgl=!!Hd.WebGLRenderingContext,F);c=d.call(c,e,b);c.ca_type="image";a&&(c.bid=a);return c}
var qi=new function(){var a=window.document;this.i=window;this.j=a};
z("yt.ads_.signals_.getAdSignalsString",function(a){return ki(pi(a))});Date.now();var ri="XMLHttpRequest"in y?function(){return new XMLHttpRequest}:null;
function si(){if(!ri)return null;var a=ri();return"open"in a?a:null}
function ti(a){switch(a&&"status"in a?a.status:-1){case 200:case 201:case 202:case 203:case 204:case 205:case 206:case 304:return!0;default:return!1}}
;function ui(a,b){"function"===typeof a&&(a=$h(a));return window.setTimeout(a,b)}
function vi(a){window.clearTimeout(a)}
;var wi={Authorization:"AUTHORIZATION","X-Goog-EOM-Visitor-Id":"EOM_VISITOR_DATA","X-Goog-Visitor-Id":"SANDBOXED_VISITOR_ID","X-Youtube-Domain-Admin-State":"DOMAIN_ADMIN_STATE","X-Youtube-Chrome-Connected":"CHROME_CONNECTED_HEADER","X-YouTube-Client-Name":"INNERTUBE_CONTEXT_CLIENT_NAME","X-YouTube-Client-Version":"INNERTUBE_CONTEXT_CLIENT_VERSION","X-YouTube-Delegation-Context":"INNERTUBE_CONTEXT_SERIALIZED_DELEGATION_CONTEXT","X-YouTube-Device":"DEVICE","X-Youtube-Identity-Token":"ID_TOKEN","X-YouTube-Page-CL":"PAGE_CL",
"X-YouTube-Page-Label":"PAGE_BUILD_LABEL","X-YouTube-Variants-Checksum":"VARIANTS_CHECKSUM"},xi="app debugcss debugjs expflag force_ad_params force_ad_encrypted force_viral_ad_response_params forced_experiments innertube_snapshots innertube_goldens internalcountrycode internalipoverride absolute_experiments conditional_experiments sbb sr_bns_address".split(" ").concat(fa(he)),yi=!1;
function zi(a,b){b=void 0===b?{}:b;var c=oi(a),d=M("web_ajax_ignore_global_headers_if_set"),e;for(e in wi){var f=L(wi[e]);M("enable_visitor_header_for_vss")&&"X-Goog-Visitor-Id"===e&&!f&&(f=L("VISITOR_DATA"));!f||!c&&bc(a)||d&&void 0!==b[e]||!M("enable_web_eom_visitor_data")&&"X-Goog-EOM-Visitor-Id"===e||(b[e]=f)}"X-Goog-EOM-Visitor-Id"in b&&"X-Goog-Visitor-Id"in b&&delete b["X-Goog-Visitor-Id"];if(c||!bc(a))b["X-YouTube-Utc-Offset"]=String(-(new Date).getTimezoneOffset());if(c||!bc(a)){try{var g=
(new Intl.DateTimeFormat).resolvedOptions().timeZone}catch(h){}g&&(b["X-YouTube-Time-Zone"]=g)}if(c||!bc(a))b["X-YouTube-Ad-Signals"]=ki(pi());return b}
function Ai(a){var b=window.location.search,c=bc(a);M("debug_handle_relative_url_for_query_forward_killswitch")||c||!oi(a)||(c=document.location.hostname);var d=$b(ac(5,a));d=(c=c&&(c.endsWith("youtube.com")||c.endsWith("youtube-nocookie.com")))&&d&&d.startsWith("/api/");if(!c||d)return a;var e=li(b),f={};db(xi,function(g){e[g]&&(f[g]=e[g])});
return ni(a,f||{},!1)}
function Wi(a,b){var c=b.format||"JSON";a=Xi(a,b);var d=Yi(a,b),e=!1,f=Zi(a,function(k){if(!e){e=!0;h&&vi(h);var m=ti(k),p=null,u=400<=k.status&&500>k.status,x=500<=k.status&&600>k.status;if(m||u||x)p=$i(a,c,k,b.convertToSafeHtml);if(m)a:if(k&&204==k.status)m=!0;else{switch(c){case "XML":m=0==parseInt(p&&p.return_code,10);break a;case "RAW":m=!0;break a}m=!!p}p=p||{};u=b.context||y;m?b.onSuccess&&b.onSuccess.call(u,k,p):b.onError&&b.onError.call(u,k,p);b.onFinish&&b.onFinish.call(u,k,p)}},b.method,
d,b.headers,b.responseType,b.withCredentials);
d=b.timeout||0;if(b.onTimeout&&0<d){var g=b.onTimeout;var h=ui(function(){e||(e=!0,f.abort(),vi(h),g.call(b.context||y,f))},d)}return f}
function Xi(a,b){b.includeDomain&&(a=document.location.protocol+"//"+document.location.hostname+(document.location.port?":"+document.location.port:"")+a);var c=L("XSRF_FIELD_NAME");if(b=b.urlParams)b[c]&&delete b[c],a=ni(a,b||{},!0);return a}
function Yi(a,b){var c=L("XSRF_FIELD_NAME"),d=L("XSRF_TOKEN"),e=b.postBody||"",f=b.postParams,g=L("XSRF_FIELD_NAME"),h;b.headers&&(h=b.headers["Content-Type"]);b.excludeXsrf||bc(a)&&!b.withCredentials&&bc(a)!=document.location.hostname||"POST"!=b.method||h&&"application/x-www-form-urlencoded"!=h||b.postParams&&b.postParams[g]||(f||(f={}),f[c]=d);f&&"string"===typeof e&&(e=li(e),wb(e,f),e=b.postBodyFormat&&"JSON"==b.postBodyFormat?JSON.stringify(e):ec(e));f=e||f&&!nb(f);!yi&&f&&"POST"!=b.method&&(yi=
!0,ai(Error("AJAX request with postData should use POST")));return e}
function $i(a,b,c,d){var e=null;switch(b){case "JSON":try{var f=c.responseText}catch(g){throw d=Error("Error reading responseText"),d.params=a,bi(d),g;}a=c.getResponseHeader("Content-Type")||"";f&&0<=a.indexOf("json")&&(")]}'\n"===f.substring(0,5)&&(f=f.substring(5)),e=JSON.parse(f));break;case "XML":if(a=(a=c.responseXML)?aj(a):null)e={},db(a.getElementsByTagName("*"),function(g){e[g.tagName]=bj(g)})}d&&cj(e);
return e}
function cj(a){if(Pa(a))for(var b in a){var c;(c="html_content"==b)||(c=b.length-5,c=0<=c&&b.indexOf("_html",c)==c);if(c){c=b;Bb("HTML that is escaped and sanitized server-side and passed through yt.net.ajax");var d=a[b],e=yb();d=e?e.createHTML(d):d;a[c]=new Sb(d)}else cj(a[b])}}
function aj(a){return a?(a=("responseXML"in a?a.responseXML:a).getElementsByTagName("root"))&&0<a.length?a[0]:null:null}
function bj(a){var b="";db(a.childNodes,function(c){b+=c.nodeValue});
return b}
function Zi(a,b,c,d,e,f,g){function h(){4==(k&&"readyState"in k?k.readyState:0)&&b&&$h(b)(k)}
c=void 0===c?"GET":c;d=void 0===d?"":d;var k=si();if(!k)return null;"onloadend"in k?k.addEventListener("loadend",h,!1):k.onreadystatechange=h;M("debug_forward_web_query_parameters")&&(a=Ai(a));k.open(c,a,!0);f&&(k.responseType=f);g&&(k.withCredentials=!0);c="POST"==c&&(void 0===window.FormData||!(d instanceof FormData));if(e=zi(a,e))for(var m in e)k.setRequestHeader(m,e[m]),"content-type"==m.toLowerCase()&&(c=!1);c&&k.setRequestHeader("Content-Type","application/x-www-form-urlencoded");k.send(d);
return k}
;function dj(a){var b=this;this.i=void 0;a.addEventListener("beforeinstallprompt",function(c){c.preventDefault();b.i=c})}
function ej(){if(!y.matchMedia)return"WEB_DISPLAY_MODE_UNKNOWN";try{return y.matchMedia("(display-mode: standalone)").matches?"WEB_DISPLAY_MODE_STANDALONE":y.matchMedia("(display-mode: minimal-ui)").matches?"WEB_DISPLAY_MODE_MINIMAL_UI":y.matchMedia("(display-mode: fullscreen)").matches?"WEB_DISPLAY_MODE_FULLSCREEN":y.matchMedia("(display-mode: browser)").matches?"WEB_DISPLAY_MODE_BROWSER":"WEB_DISPLAY_MODE_UNKNOWN"}catch(a){return"WEB_DISPLAY_MODE_UNKNOWN"}}
;function fj(a,b,c,d,e){pe.set(""+a,b,{Qa:c,path:"/",domain:void 0===d?"youtube.com":d,secure:void 0===e?!1:e})}
function gj(a){return pe.get(""+a,void 0)}
function hj(){if(!pe.isEnabled())return!1;if(!pe.isEmpty())return!0;pe.set("TESTCOOKIESENABLED","1",{Qa:60});if("1"!==pe.get("TESTCOOKIESENABLED"))return!1;pe.remove("TESTCOOKIESENABLED");return!0}
;var ij=A("ytglobal.prefsUserPrefsPrefs_")||{};z("ytglobal.prefsUserPrefsPrefs_",ij);function jj(){this.i=L("ALT_PREF_COOKIE_NAME","PREF");this.j=L("ALT_PREF_COOKIE_DOMAIN","youtube.com");var a=gj(this.i);if(a){a=decodeURIComponent(a).split("&");for(var b=0;b<a.length;b++){var c=a[b].split("="),d=c[0];(c=c[1])&&(ij[d]=c.toString())}}}
jj.prototype.get=function(a,b){kj(a);lj(a);a=void 0!==ij[a]?ij[a].toString():null;return null!=a?a:b?b:""};
jj.prototype.set=function(a,b){kj(a);lj(a);if(null==b)throw Error("ExpectedNotNull");ij[a]=b.toString()};
function mj(a){return!!((nj("f"+(Math.floor(a/31)+1))||0)&1<<a%31)}
jj.prototype.remove=function(a){kj(a);lj(a);delete ij[a]};
jj.prototype.clear=function(){for(var a in ij)delete ij[a]};
function lj(a){if(/^f([1-9][0-9]*)$/.test(a))throw Error("ExpectedRegexMatch: "+a);}
function kj(a){if(!/^\w+$/.test(a))throw Error("ExpectedRegexMismatch: "+a);}
function nj(a){a=void 0!==ij[a]?ij[a].toString():null;return null!=a&&/^[A-Fa-f0-9]+$/.test(a)?parseInt(a,16):null}
La(jj);var oj={bluetooth:"CONN_DISCO",cellular:"CONN_CELLULAR_UNKNOWN",ethernet:"CONN_WIFI",none:"CONN_NONE",wifi:"CONN_WIFI",wimax:"CONN_CELLULAR_4G",other:"CONN_UNKNOWN",unknown:"CONN_UNKNOWN","slow-2g":"CONN_CELLULAR_2G","2g":"CONN_CELLULAR_2G","3g":"CONN_CELLULAR_3G","4g":"CONN_CELLULAR_4G"},pj={CONN_DEFAULT:0,CONN_UNKNOWN:1,CONN_NONE:2,CONN_WIFI:3,CONN_CELLULAR_2G:4,CONN_CELLULAR_3G:5,CONN_CELLULAR_4G:6,CONN_CELLULAR_UNKNOWN:7,CONN_DISCO:8,CONN_CELLULAR_5G:9,CONN_WIFI_METERED:10,CONN_CELLULAR_5G_SA:11,
CONN_CELLULAR_5G_NSA:12,CONN_INVALID:31},qj={EFFECTIVE_CONNECTION_TYPE_UNKNOWN:0,EFFECTIVE_CONNECTION_TYPE_OFFLINE:1,EFFECTIVE_CONNECTION_TYPE_SLOW_2G:2,EFFECTIVE_CONNECTION_TYPE_2G:3,EFFECTIVE_CONNECTION_TYPE_3G:4,EFFECTIVE_CONNECTION_TYPE_4G:5},rj={"slow-2g":"EFFECTIVE_CONNECTION_TYPE_SLOW_2G","2g":"EFFECTIVE_CONNECTION_TYPE_2G","3g":"EFFECTIVE_CONNECTION_TYPE_3G","4g":"EFFECTIVE_CONNECTION_TYPE_4G"};function sj(){var a=y.navigator;return a?a.connection:void 0}
function tj(){var a=sj();if(a){var b=oj[a.type||"unknown"]||"CONN_UNKNOWN";a=oj[a.effectiveType||"unknown"]||"CONN_UNKNOWN";"CONN_CELLULAR_UNKNOWN"===b&&"CONN_UNKNOWN"!==a&&(b=a);if("CONN_UNKNOWN"!==b)return b;if("CONN_UNKNOWN"!==a)return a}}
function uj(){var a=sj();if(null!=a&&a.effectiveType)return rj.hasOwnProperty(a.effectiveType)?rj[a.effectiveType]:"EFFECTIVE_CONNECTION_TYPE_UNKNOWN"}
;function vj(){return"INNERTUBE_API_KEY"in Rh&&"INNERTUBE_API_VERSION"in Rh}
function wj(){return{innertubeApiKey:L("INNERTUBE_API_KEY"),innertubeApiVersion:L("INNERTUBE_API_VERSION"),eb:L("INNERTUBE_CONTEXT_CLIENT_CONFIG_INFO"),zb:L("INNERTUBE_CONTEXT_CLIENT_NAME","WEB"),Zb:L("INNERTUBE_CONTEXT_CLIENT_NAME",1),innertubeContextClientVersion:L("INNERTUBE_CONTEXT_CLIENT_VERSION"),Bb:L("INNERTUBE_CONTEXT_HL"),Ab:L("INNERTUBE_CONTEXT_GL"),ac:L("INNERTUBE_HOST_OVERRIDE")||"",dc:!!L("INNERTUBE_USE_THIRD_PARTY_AUTH",!1),cc:!!L("INNERTUBE_OMIT_API_KEY_WHEN_AUTH_HEADER_IS_PRESENT",
!1),appInstallData:L("SERIALIZED_CLIENT_CONFIG_DATA")}}
function xj(a){var b={client:{hl:a.Bb,gl:a.Ab,clientName:a.zb,clientVersion:a.innertubeContextClientVersion,configInfo:a.eb}};navigator.userAgent&&(b.client.userAgent=String(navigator.userAgent));var c=y.devicePixelRatio;c&&1!=c&&(b.client.screenDensityFloat=String(c));c=Wh();""!==c&&(b.client.experimentsToken=c);c=Xh();0<c.length&&(b.request={internalExperimentFlags:c});yj(a,void 0,b);zj(void 0,b);Aj(a,void 0,b);Bj(void 0,b);L("DELEGATED_SESSION_ID")&&!M("pageid_as_header_web")&&(b.user={onBehalfOfUser:L("DELEGATED_SESSION_ID")});
a=Object;c=a.assign;for(var d=b.client,e={},f=q(Object.entries(li(L("DEVICE","")))),g=f.next();!g.done;g=f.next()){var h=q(g.value);g=h.next().value;h=h.next().value;"cbrand"===g?e.deviceMake=h:"cmodel"===g?e.deviceModel=h:"cbr"===g?e.browserName=h:"cbrver"===g?e.browserVersion=h:"cos"===g?e.osName=h:"cosver"===g?e.osVersion=h:"cplatform"===g&&(e.platform=h)}b.client=c.call(a,d,e);return b}
function Cj(a){var b=new Ug,c=new Ng;C(c,1,a.Bb);C(c,2,a.Ab);C(c,16,a.Zb);C(c,17,a.innertubeContextClientVersion);if(a.eb){var d=a.eb,e=new Lg;d.coldConfigData&&C(e,1,d.coldConfigData);d.appInstallData&&C(e,6,d.appInstallData);d.coldHashData&&C(e,3,d.coldHashData);d.hotHashData&&C(e,5,d.hotHashData);D(c,62,e)}(d=y.devicePixelRatio)&&1!=d&&C(c,65,d);d=Wh();""!==d&&C(c,54,d);d=Xh();if(0<d.length){e=new Pg;for(var f=0;f<d.length;f++){var g=new Jg;C(g,1,d[f].key);g.setValue(d[f].value);vd(e,15,Jg,g)}D(b,
5,e)}yj(a,c);zj(c);Aj(a,c);Bj(c);L("DELEGATED_SESSION_ID")&&!M("pageid_as_header_web")&&(a=new Sg,C(a,3,L("DELEGATED_SESSION_ID")));a=q(Object.entries(li(L("DEVICE",""))));for(d=a.next();!d.done;d=a.next())e=q(d.value),d=e.next().value,e=e.next().value,"cbrand"===d?C(c,12,e):"cmodel"===d?C(c,13,e):"cbr"===d?C(c,87,e):"cbrver"===d?C(c,88,e):"cos"===d?C(c,18,e):"cosver"===d?C(c,19,e):"cplatform"===d&&C(c,42,e);D(b,1,c);return b}
function yj(a,b,c){a=a.zb;if("WEB"===a||"MWEB"===a||1===a||2===a)if(b){c=sd(b,Mg,96)||new Mg;var d=ej();d=Object.keys(jf).indexOf(d);d=-1===d?null:d;null!==d&&C(c,3,d);D(b,96,c)}else c&&(c.client.mainAppWebInfo=null!=(d=c.client.mainAppWebInfo)?d:{},c.client.mainAppWebInfo.webDisplayMode=ej())}
function zj(a,b){var c;if(M("web_log_memory_total_kbytes")&&(null==(c=y.navigator)?0:c.deviceMemory)){var d;c=null==(d=y.navigator)?void 0:d.deviceMemory;a?C(a,95,1E6*c):b&&(b.client.memoryTotalKbytes=""+1E6*c)}}
function Aj(a,b,c){if(a.appInstallData)if(b){var d;c=null!=(d=sd(b,Lg,62))?d:new Lg;C(c,6,a.appInstallData);D(b,62,c)}else c&&(c.client.configInfo=c.client.configInfo||{},c.client.configInfo.appInstallData=a.appInstallData)}
function Bj(a,b){var c=tj();c&&(a?C(a,61,pj[c]):b&&(b.client.connectionType=c));M("web_log_effective_connection_type")&&(c=uj())&&(a?C(a,94,qj[c]):b&&(b.client.effectiveConnectionType=c))}
function Dj(a,b,c){c=void 0===c?{}:c;var d={};M("enable_web_eom_visitor_data")&&L("EOM_VISITOR_DATA")?d={"X-Goog-EOM-Visitor-Id":L("EOM_VISITOR_DATA")}:d={"X-Goog-Visitor-Id":c.visitorData||L("VISITOR_DATA","")};if(b&&b.includes("www.youtube-nocookie.com"))return d;(b=c.lp||L("AUTHORIZATION"))||(a?b="Bearer "+A("gapi.auth.getToken")().kp:b=te([]));b&&(d.Authorization=b,d["X-Goog-AuthUser"]=L("SESSION_INDEX",0),M("pageid_as_header_web")&&(d["X-Goog-PageId"]=L("DELEGATED_SESSION_ID")));return d}
;function Ej(a){a=Object.assign({},a);delete a.Authorization;var b=te();if(b){var c=new Cf;c.update(L("INNERTUBE_API_KEY"));c.update(b);a.hash=Lc(c.digest(),3)}return a}
;function Fj(a){var b=new Cg;(b=b.isAvailable()?a?new Ig(b,a):b:null)||(a=new Dg(a||"UserDataSharedStore"),b=a.isAvailable()?a:null);this.i=(a=b)?new yg(a):null;this.j=document.domain||window.location.hostname}
Fj.prototype.set=function(a,b,c,d){c=c||31104E3;this.remove(a);if(this.i)try{this.i.set(a,b,Date.now()+1E3*c);return}catch(f){}var e="";if(d)try{e=escape(Vf(b))}catch(f){return}else e=escape(b);fj(a,e,c,this.j)};
Fj.prototype.get=function(a,b){var c=void 0,d=!this.i;if(!d)try{c=this.i.get(a)}catch(e){d=!0}if(d&&(c=gj(a))&&(c=unescape(c),b))try{c=JSON.parse(c)}catch(e){this.remove(a),c=void 0}return c};
Fj.prototype.remove=function(a){this.i&&this.i.remove(a);var b=this.j;pe.remove(""+a,"/",void 0===b?"youtube.com":b)};var Gj=window,P=Gj.ytcsi&&Gj.ytcsi.now?Gj.ytcsi.now:Gj.performance&&Gj.performance.timing&&Gj.performance.now&&Gj.performance.timing.navigationStart?function(){return Gj.performance.timing.navigationStart+Gj.performance.now()}:function(){return(new Date).getTime()};var Hj;function Ij(){Hj||(Hj=new Fj("yt.innertube"));return Hj}
function Jj(a,b,c,d){if(d)return null;d=Ij().get("nextId",!0)||1;var e=Ij().get("requests",!0)||{};e[d]={method:a,request:b,authState:Ej(c),requestTime:Math.round(P())};Ij().set("nextId",d+1,86400,!0);Ij().set("requests",e,86400,!0);return d}
function Kj(a){var b=Ij().get("requests",!0)||{};delete b[a];Ij().set("requests",b,86400,!0)}
function Lj(a){var b=Ij().get("requests",!0);if(b){for(var c in b){var d=b[c];if(!(6E4>Math.round(P())-d.requestTime)){var e=d.authState,f=Ej(Dj(!1));qb(e,f)&&(e=d.request,"requestTimeMs"in e&&(e.requestTimeMs=Math.round(P())),Mj(a,d.method,e,{}));delete b[c]}}Ij().set("requests",b,86400,!0)}}
;function Nj(){}
function Oj(a,b){return Pj(a,0,b)}
Nj.prototype.M=function(a,b){return Pj(a,1,b)};
function Qj(a,b){Pj(a,2,b)}
function Rj(a){var b=A("yt.scheduler.instance.addImmediateJob");b?b(a):a()}
;function Sj(){Nj.apply(this,arguments)}
r(Sj,Nj);function Tj(){Sj.i||(Sj.i=new Sj);return Sj.i}
function Pj(a,b,c){void 0!==c&&Number.isNaN(Number(c))&&(c=void 0);var d=A("yt.scheduler.instance.addJob");return d?d(a,b,c):void 0===c?(a(),NaN):ui(a,c||0)}
Sj.prototype.S=function(a){if(void 0===a||!Number.isNaN(Number(a))){var b=A("yt.scheduler.instance.cancelJob");b?b(a):vi(a)}};
Sj.prototype.start=function(){var a=A("yt.scheduler.instance.start");a&&a()};
Sj.prototype.pause=function(){var a=A("yt.scheduler.instance.pause");a&&a()};var gf=Tj();var Uj=Gc||Hc;function Vj(a){var b=Pb();return b?0<=b.toLowerCase().indexOf(a):!1}
;var Wj=function(){var a;return function(){a||(a=new Fj("ytidb"));return a}}();
function Xj(){var a;return null==(a=Wj())?void 0:a.get("LAST_RESULT_ENTRY_KEY",!0)}
;var Yj=[],Zj,ak=!1;function bk(){var a={};for(Zj=new ck(void 0===a.handleError?dk:a.handleError,void 0===a.logEvent?ek:a.logEvent);0<Yj.length;)switch(a=Yj.shift(),a.type){case "ERROR":Zj.handleError(a.payload);break;case "EVENT":Zj.logEvent(a.eventType,a.payload)}}
function fk(a){ak||(Zj?Zj.handleError(a):(Yj.push({type:"ERROR",payload:a}),10<Yj.length&&Yj.shift()))}
function gk(a,b){ak||(Zj?Zj.logEvent(a,b):(Yj.push({type:"EVENT",eventType:a,payload:b}),10<Yj.length&&Yj.shift()))}
;function hk(a){var b=Ia.apply(1,arguments);var c=Error.call(this,a);this.message=c.message;"stack"in c&&(this.stack=c.stack);this.args=[].concat(fa(b))}
r(hk,Error);function ik(){try{return jk(),!0}catch(a){return!1}}
function jk(a){if(void 0!==L("DATASYNC_ID"))return L("DATASYNC_ID");throw new hk("Datasync ID not set",void 0===a?"unknown":a);}
;function kk(a){if(0<=a.indexOf(":"))throw Error("Database name cannot contain ':'");}
function lk(a){return a.substr(0,a.indexOf(":"))||a}
;var mk={},nk=(mk.AUTH_INVALID="No user identifier specified.",mk.EXPLICIT_ABORT="Transaction was explicitly aborted.",mk.IDB_NOT_SUPPORTED="IndexedDB is not supported.",mk.MISSING_INDEX="Index not created.",mk.MISSING_OBJECT_STORES="Object stores not created.",mk.DB_DELETED_BY_MISSING_OBJECT_STORES="Database is deleted because expected object stores were not created.",mk.DB_REOPENED_BY_MISSING_OBJECT_STORES="Database is reopened because expected object stores were not created.",mk.UNKNOWN_ABORT="Transaction was aborted for unknown reasons.",
mk.QUOTA_EXCEEDED="The current transaction exceeded its quota limitations.",mk.QUOTA_MAYBE_EXCEEDED="The current transaction may have failed because of exceeding quota limitations.",mk.EXECUTE_TRANSACTION_ON_CLOSED_DB="Can't start a transaction on a closed database",mk.INCOMPATIBLE_DB_VERSION="The binary is incompatible with the database version",mk),ok={},pk=(ok.AUTH_INVALID="ERROR",ok.EXECUTE_TRANSACTION_ON_CLOSED_DB="WARNING",ok.EXPLICIT_ABORT="IGNORED",ok.IDB_NOT_SUPPORTED="ERROR",ok.MISSING_INDEX=
"WARNING",ok.MISSING_OBJECT_STORES="ERROR",ok.DB_DELETED_BY_MISSING_OBJECT_STORES="WARNING",ok.DB_REOPENED_BY_MISSING_OBJECT_STORES="WARNING",ok.QUOTA_EXCEEDED="WARNING",ok.QUOTA_MAYBE_EXCEEDED="WARNING",ok.UNKNOWN_ABORT="WARNING",ok.INCOMPATIBLE_DB_VERSION="WARNING",ok),qk={},rk=(qk.AUTH_INVALID=!1,qk.EXECUTE_TRANSACTION_ON_CLOSED_DB=!1,qk.EXPLICIT_ABORT=!1,qk.IDB_NOT_SUPPORTED=!1,qk.MISSING_INDEX=!1,qk.MISSING_OBJECT_STORES=!1,qk.DB_DELETED_BY_MISSING_OBJECT_STORES=!1,qk.DB_REOPENED_BY_MISSING_OBJECT_STORES=
!1,qk.QUOTA_EXCEEDED=!1,qk.QUOTA_MAYBE_EXCEEDED=!0,qk.UNKNOWN_ABORT=!0,qk.INCOMPATIBLE_DB_VERSION=!1,qk);function sk(a,b,c,d,e){b=void 0===b?{}:b;c=void 0===c?nk[a]:c;d=void 0===d?pk[a]:d;e=void 0===e?rk[a]:e;hk.call(this,c,Object.assign({},{name:"YtIdbKnownError",isSw:void 0===self.document,isIframe:self!==self.top,type:a},b));this.type=a;this.message=c;this.level=d;this.i=e;Object.setPrototypeOf(this,sk.prototype)}
r(sk,hk);function tk(a,b){sk.call(this,"MISSING_OBJECT_STORES",{expectedObjectStores:b,foundObjectStores:a},nk.MISSING_OBJECT_STORES);Object.setPrototypeOf(this,tk.prototype)}
r(tk,sk);function uk(a,b){var c=Error.call(this);this.message=c.message;"stack"in c&&(this.stack=c.stack);this.index=a;this.objectStore=b;Object.setPrototypeOf(this,uk.prototype)}
r(uk,Error);var vk=["The database connection is closing","Can't start a transaction on a closed database","A mutation operation was attempted on a database that did not allow mutations"];
function wk(a,b,c,d){b=lk(b);var e=a instanceof Error?a:Error("Unexpected error: "+a);if(e instanceof sk)return e;a={objectStoreNames:c,dbName:b,dbVersion:d};if("QuotaExceededError"===e.name)return new sk("QUOTA_EXCEEDED",a);if(Ic&&"UnknownError"===e.name)return new sk("QUOTA_MAYBE_EXCEEDED",a);if(e instanceof uk)return new sk("MISSING_INDEX",Object.assign({},a,{objectStore:e.objectStore,index:e.index}));if("InvalidStateError"===e.name&&vk.some(function(f){return e.message.includes(f)}))return new sk("EXECUTE_TRANSACTION_ON_CLOSED_DB",
a);
if("AbortError"===e.name)return new sk("UNKNOWN_ABORT",a,e.message);e.args=[Object.assign({},a,{name:"IdbError",Fb:e.name})];e.level="WARNING";return e}
function xk(a,b,c){var d=Xj();return new sk("IDB_NOT_SUPPORTED",{context:{caller:a,publicName:b,version:c,hasSucceededOnce:null==d?void 0:d.hasSucceededOnce}})}
;function yk(a){if(!a)throw Error();throw a;}
function zk(a){return a}
function Ak(a){this.i=a}
function Bk(a){function b(e){if("PENDING"===d.state.status){d.state={status:"REJECTED",reason:e};e=q(d.onRejected);for(var f=e.next();!f.done;f=e.next())f=f.value,f()}}
function c(e){if("PENDING"===d.state.status){d.state={status:"FULFILLED",value:e};e=q(d.i);for(var f=e.next();!f.done;f=e.next())f=f.value,f()}}
var d=this;this.state={status:"PENDING"};this.i=[];this.onRejected=[];a=a.i;try{a(c,b)}catch(e){b(e)}}
Bk.all=function(a){return new Bk(new Ak(function(b,c){var d=[],e=a.length;0===e&&b(d);for(var f={ma:0};f.ma<a.length;f={ma:f.ma},++f.ma)Ck(Bk.resolve(a[f.ma]).then(function(g){return function(h){d[g.ma]=h;e--;0===e&&b(d)}}(f)),function(g){c(g)})}))};
Bk.resolve=function(a){return new Bk(new Ak(function(b,c){a instanceof Bk?a.then(b,c):b(a)}))};
Bk.reject=function(a){return new Bk(new Ak(function(b,c){c(a)}))};
Bk.prototype.then=function(a,b){var c=this,d=null!=a?a:zk,e=null!=b?b:yk;return new Bk(new Ak(function(f,g){"PENDING"===c.state.status?(c.i.push(function(){Dk(c,c,d,f,g)}),c.onRejected.push(function(){Ek(c,c,e,f,g)})):"FULFILLED"===c.state.status?Dk(c,c,d,f,g):"REJECTED"===c.state.status&&Ek(c,c,e,f,g)}))};
function Ck(a,b){a.then(void 0,b)}
function Dk(a,b,c,d,e){try{if("FULFILLED"!==a.state.status)throw Error("calling handleResolve before the promise is fulfilled.");var f=c(a.state.value);f instanceof Bk?Fk(a,b,f,d,e):d(f)}catch(g){e(g)}}
function Ek(a,b,c,d,e){try{if("REJECTED"!==a.state.status)throw Error("calling handleReject before the promise is rejected.");var f=c(a.state.reason);f instanceof Bk?Fk(a,b,f,d,e):d(f)}catch(g){e(g)}}
function Fk(a,b,c,d,e){b===c?e(new TypeError("Circular promise chain detected.")):c.then(function(f){f instanceof Bk?Fk(a,b,f,d,e):d(f)},function(f){e(f)})}
;function Gk(a,b,c){function d(){c(a.error);f()}
function e(){b(a.result);f()}
function f(){try{a.removeEventListener("success",e),a.removeEventListener("error",d)}catch(g){}}
a.addEventListener("success",e);a.addEventListener("error",d)}
function Hk(a){return new Promise(function(b,c){Gk(a,b,c)})}
function Ik(a){return new Bk(new Ak(function(b,c){Gk(a,b,c)}))}
;function Jk(a,b){return new Bk(new Ak(function(c,d){function e(){var f=a?b(a):null;f?f.then(function(g){a=g;e()},d):c()}
e()}))}
;function Kk(a,b){this.i=a;this.options=b;this.transactionCount=0;this.l=Math.round(P());this.j=!1}
l=Kk.prototype;l.add=function(a,b,c){return Lk(this,[a],{mode:"readwrite",O:!0},function(d){return d.objectStore(a).add(b,c)})};
l.clear=function(a){return Lk(this,[a],{mode:"readwrite",O:!0},function(b){return b.objectStore(a).clear()})};
l.close=function(){this.i.close();var a;(null==(a=this.options)?0:a.closed)&&this.options.closed()};
l.count=function(a,b){return Lk(this,[a],{mode:"readonly",O:!0},function(c){return c.objectStore(a).count(b)})};
function Mk(a,b,c){a=a.i.createObjectStore(b,c);return new Nk(a)}
l.delete=function(a,b){return Lk(this,[a],{mode:"readwrite",O:!0},function(c){return c.objectStore(a).delete(b)})};
l.get=function(a,b){return Lk(this,[a],{mode:"readonly",O:!0},function(c){return c.objectStore(a).get(b)})};
function Ok(a,b){return Lk(a,["LogsRequestsStore"],{mode:"readwrite",O:!0},function(c){c=c.objectStore("LogsRequestsStore");return Ik(c.i.put(b,void 0))})}
l.objectStoreNames=function(){return Array.from(this.i.objectStoreNames)};
function Lk(a,b,c,d){var e,f,g,h,k,m,p,u,x,v,E,G;return w(function(K){switch(K.i){case 1:var N={mode:"readonly",O:!1,tag:"IDB_TRANSACTION_TAG_UNKNOWN"};"string"===typeof c?N.mode=c:Object.assign(N,c);e=N;a.transactionCount++;f=e.O?3:1;g=0;case 2:if(h){K.u(3);break}g++;k=Math.round(P());ua(K,4);m=a.i.transaction(b,e.mode);N=new Pk(m);N=Qk(N,d);return t(K,N,6);case 6:return p=K.j,u=Math.round(P()),Rk(a,k,u,g,void 0,b.join(),e),K.return(p);case 4:x=ya(K);v=Math.round(P());E=wk(x,a.i.name,b.join(),a.i.version);
if((G=E instanceof sk&&!E.i)||g>=f)Rk(a,k,v,g,E,b.join(),e),h=E;K.u(2);break;case 3:return K.return(Promise.reject(h))}})}
function Rk(a,b,c,d,e,f,g){b=c-b;e?(e instanceof sk&&("QUOTA_EXCEEDED"===e.type||"QUOTA_MAYBE_EXCEEDED"===e.type)&&gk("QUOTA_EXCEEDED",{dbName:lk(a.i.name),objectStoreNames:f,transactionCount:a.transactionCount,transactionMode:g.mode}),e instanceof sk&&"UNKNOWN_ABORT"===e.type&&(c-=a.l,0>c&&c>=Math.pow(2,31)&&(c=0),gk("TRANSACTION_UNEXPECTEDLY_ABORTED",{objectStoreNames:f,transactionDuration:b,transactionCount:a.transactionCount,dbDuration:c}),a.j=!0),Sk(a,!1,d,f,b,g.tag),fk(e)):Sk(a,!0,d,f,b,g.tag)}
function Sk(a,b,c,d,e,f){gk("TRANSACTION_ENDED",{objectStoreNames:d,connectionHasUnknownAbortedTransaction:a.j,duration:e,isSuccessful:b,tryCount:c,tag:void 0===f?"IDB_TRANSACTION_TAG_UNKNOWN":f})}
l.getName=function(){return this.i.name};
function Nk(a){this.i=a}
l=Nk.prototype;l.add=function(a,b){return Ik(this.i.add(a,b))};
l.autoIncrement=function(){return this.i.autoIncrement};
l.clear=function(){return Ik(this.i.clear()).then(function(){})};
l.count=function(a){return Ik(this.i.count(a))};
function Tk(a,b){return Uk(a,{query:b},function(c){return c.delete().then(function(){return c.continue()})}).then(function(){})}
l.delete=function(a){return a instanceof IDBKeyRange?Tk(this,a):Ik(this.i.delete(a))};
l.get=function(a){return Ik(this.i.get(a))};
l.index=function(a){try{return new Vk(this.i.index(a))}catch(b){if(b instanceof Error&&"NotFoundError"===b.name)throw new uk(a,this.i.name);throw b;}};
l.getName=function(){return this.i.name};
l.keyPath=function(){return this.i.keyPath};
function Uk(a,b,c){a=a.i.openCursor(b.query,b.direction);return Wk(a).then(function(d){return Jk(d,c)})}
function Pk(a){var b=this;this.i=a;this.l=new Map;this.j=!1;this.done=new Promise(function(c,d){b.i.addEventListener("complete",function(){c()});
b.i.addEventListener("error",function(e){e.currentTarget===e.target&&d(b.i.error)});
b.i.addEventListener("abort",function(){var e=b.i.error;if(e)d(e);else if(!b.j){e=sk;for(var f=b.i.objectStoreNames,g=[],h=0;h<f.length;h++){var k=f.item(h);if(null===k)throw Error("Invariant: item in DOMStringList is null");g.push(k)}e=new e("UNKNOWN_ABORT",{objectStoreNames:g.join(),dbName:b.i.db.name,mode:b.i.mode});d(e)}})})}
function Qk(a,b){var c=new Promise(function(d,e){try{Ck(b(a).then(function(f){d(f)}),e)}catch(f){e(f),a.abort()}});
return Promise.all([c,a.done]).then(function(d){return q(d).next().value})}
Pk.prototype.abort=function(){this.i.abort();this.j=!0;throw new sk("EXPLICIT_ABORT");};
Pk.prototype.objectStore=function(a){a=this.i.objectStore(a);var b=this.l.get(a);b||(b=new Nk(a),this.l.set(a,b));return b};
function Vk(a){this.i=a}
l=Vk.prototype;l.count=function(a){return Ik(this.i.count(a))};
l.delete=function(a){return Xk(this,{query:a},function(b){return b.delete().then(function(){return b.continue()})})};
l.get=function(a){return Ik(this.i.get(a))};
l.getKey=function(a){return Ik(this.i.getKey(a))};
l.keyPath=function(){return this.i.keyPath};
l.unique=function(){return this.i.unique};
function Xk(a,b,c){a=a.i.openCursor(void 0===b.query?null:b.query,void 0===b.direction?"next":b.direction);return Wk(a).then(function(d){return Jk(d,c)})}
function Yk(a,b){this.request=a;this.cursor=b}
function Wk(a){return Ik(a).then(function(b){return b?new Yk(a,b):null})}
l=Yk.prototype;l.advance=function(a){this.cursor.advance(a);return Wk(this.request)};
l.continue=function(a){this.cursor.continue(a);return Wk(this.request)};
l.delete=function(){return Ik(this.cursor.delete()).then(function(){})};
l.getKey=function(){return this.cursor.key};
l.getValue=function(){return this.cursor.value};
l.update=function(a){return Ik(this.cursor.update(a))};function Zk(a,b,c){return new Promise(function(d,e){function f(){x||(x=new Kk(g.result,{closed:u}));return x}
var g=void 0!==b?self.indexedDB.open(a,b):self.indexedDB.open(a);var h=c.blocked,k=c.blocking,m=c.Dc,p=c.upgrade,u=c.closed,x;g.addEventListener("upgradeneeded",function(v){try{if(null===v.newVersion)throw Error("Invariant: newVersion on IDbVersionChangeEvent is null");if(null===g.transaction)throw Error("Invariant: transaction on IDbOpenDbRequest is null");v.dataLoss&&"none"!==v.dataLoss&&gk("IDB_DATA_CORRUPTED",{reason:v.dataLossMessage||"unknown reason",dbName:lk(a)});var E=f(),G=new Pk(g.transaction);
p&&p(E,function(K){return v.oldVersion<K&&v.newVersion>=K},G);
G.done.catch(function(K){e(K)})}catch(K){e(K)}});
g.addEventListener("success",function(){var v=g.result;k&&v.addEventListener("versionchange",function(){k(f())});
v.addEventListener("close",function(){gk("IDB_UNEXPECTEDLY_CLOSED",{dbName:lk(a),dbVersion:v.version});m&&m()});
d(f())});
g.addEventListener("error",function(){e(g.error)});
h&&g.addEventListener("blocked",function(){h()})})}
function $k(a,b,c){c=void 0===c?{}:c;return Zk(a,b,c)}
function al(a,b){b=void 0===b?{}:b;var c,d,e,f;return w(function(g){if(1==g.i)return ua(g,2),c=self.indexedDB.deleteDatabase(a),d=b,(e=d.blocked)&&c.addEventListener("blocked",function(){e()}),t(g,Hk(c),4);
if(2!=g.i)return xa(g,0);f=ya(g);throw wk(f,a,"",-1);})}
;function bl(a){return new Promise(function(b){Qj(function(){b()},a)})}
function cl(a,b){this.name=a;this.options=b;this.m=!0;this.o=this.s=0;this.j=500}
cl.prototype.l=function(a,b,c){c=void 0===c?{}:c;return $k(a,b,c)};
cl.prototype.delete=function(a){a=void 0===a?{}:a;return al(this.name,a)};
function dl(a,b){return new sk("INCOMPATIBLE_DB_VERSION",{dbName:a.name,oldVersion:a.options.version,newVersion:b})}
function el(a,b){if(!b)throw xk("openWithToken",lk(a.name));return fl(a)}
function fl(a){function b(){var f,g,h,k,m,p,u,x,v,E;return w(function(G){switch(G.i){case 1:return g=null!=(f=Error().stack)?f:"",ua(G,2),t(G,a.l(a.name,a.options.version,d),4);case 4:h=G.j;for(var K=a.options,N=[],O=q(Object.keys(K.ya)),S=O.next();!S.done;S=O.next()){S=S.value;var ka=K.ya[S],V=void 0===ka.mc?Number.MAX_VALUE:ka.mc;!(h.i.version>=ka.Xa)||h.i.version>=V||h.i.objectStoreNames.contains(S)||N.push(S)}k=N;if(0===k.length){G.u(5);break}m=Object.keys(a.options.ya);p=h.objectStoreNames();
if(a.o<Vh("ytidb_reopen_db_retries",0))return a.o++,h.close(),fk(new sk("DB_REOPENED_BY_MISSING_OBJECT_STORES",{dbName:a.name,expectedObjectStores:m,foundObjectStores:p})),G.return(b());if(!(a.s<Vh("ytidb_remake_db_retries",1))){G.u(6);break}a.s++;if(!M("ytidb_remake_db_enable_backoff_delay")){G.u(7);break}return t(G,bl(a.j),8);case 8:a.j*=2;case 7:return t(G,a.delete(),9);case 9:return fk(new sk("DB_DELETED_BY_MISSING_OBJECT_STORES",{dbName:a.name,expectedObjectStores:m,foundObjectStores:p})),G.return(b());
case 6:throw new tk(p,m);case 5:return G.return(h);case 2:u=ya(G);if(u instanceof DOMException?"VersionError"!==u.name:"DOMError"in self&&u instanceof DOMError?"VersionError"!==u.name:!(u instanceof Object&&"message"in u)||"An attempt was made to open a database using a lower version than the existing version."!==u.message){G.u(10);break}return t(G,a.l(a.name,void 0,Object.assign({},d,{upgrade:void 0})),11);case 11:x=G.j;v=x.i.version;if(void 0!==a.options.version&&v>a.options.version+1)throw x.close(),
a.m=!1,dl(a,v);return G.return(x);case 10:throw c(),u instanceof Error&&!M("ytidb_async_stack_killswitch")&&(u.stack=u.stack+"\n"+g.substring(g.indexOf("\n")+1)),wk(u,a.name,"",null!=(E=a.options.version)?E:-1);}})}
function c(){a.i===e&&(a.i=void 0)}
if(!a.m)throw dl(a);if(a.i)return a.i;var d={blocking:function(f){f.close()},
closed:c,Dc:c,upgrade:a.options.upgrade};var e=b();a.i=e;return a.i}
;var gl=new cl("YtIdbMeta",{ya:{databases:{Xa:1}},upgrade:function(a,b){b(1)&&Mk(a,"databases",{keyPath:"actualName"})}});
function hl(a,b){var c;return w(function(d){if(1==d.i)return t(d,el(gl,b),2);c=d.j;return d.return(Lk(c,["databases"],{O:!0,mode:"readwrite"},function(e){var f=e.objectStore("databases");return f.get(a.actualName).then(function(g){if(g?a.actualName!==g.actualName||a.publicName!==g.publicName||a.userIdentifier!==g.userIdentifier:1)return Ik(f.i.put(a,void 0)).then(function(){})})}))})}
function il(a,b){var c;return w(function(d){if(1==d.i)return a?t(d,el(gl,b),2):d.return();c=d.j;return d.return(c.delete("databases",a))})}
function jl(a,b){var c,d;return w(function(e){return 1==e.i?(c=[],t(e,el(gl,b),2)):3!=e.i?(d=e.j,t(e,Lk(d,["databases"],{O:!0,mode:"readonly"},function(f){c.length=0;return Uk(f.objectStore("databases"),{},function(g){a(g.getValue())&&c.push(g.getValue());return g.continue()})}),3)):e.return(c)})}
function kl(a){return jl(function(b){return"LogsDatabaseV2"===b.publicName&&void 0!==b.userIdentifier},a)}
function ll(a,b,c){return jl(function(d){return c?void 0!==d.userIdentifier&&!a.includes(d.userIdentifier)&&c.includes(d.publicName):void 0!==d.userIdentifier&&!a.includes(d.userIdentifier)},b)}
function ml(a){var b,c;return w(function(d){if(1==d.i)return b=jk("YtIdbMeta hasAnyMeta other"),t(d,jl(function(e){return void 0!==e.userIdentifier&&e.userIdentifier!==b},a),2);
c=d.j;return d.return(0<c.length)})}
;var nl,ol=new function(){}(new function(){});
function pl(){var a,b,c,d;return w(function(e){switch(e.i){case 1:a=Xj();if(null==(b=a)?0:b.hasSucceededOnce)return e.return(!0);var f;if(f=Uj)f=/WebKit\/([0-9]+)/.exec(Pb()),f=!!(f&&600<=parseInt(f[1],10));f&&(f=/WebKit\/([0-9]+)/.exec(Pb()),f=!(f&&602<=parseInt(f[1],10)));if(f||tc)return e.return(!1);try{if(c=self,!(c.indexedDB&&c.IDBIndex&&c.IDBKeyRange&&c.IDBObjectStore))return e.return(!1)}catch(g){return e.return(!1)}if(!("IDBTransaction"in self&&"objectStoreNames"in IDBTransaction.prototype))return e.return(!1);
ua(e,2);d={actualName:"yt-idb-test-do-not-use",publicName:"yt-idb-test-do-not-use",userIdentifier:void 0};return t(e,hl(d,ol),4);case 4:return t(e,il("yt-idb-test-do-not-use",ol),5);case 5:return e.return(!0);case 2:return ya(e),e.return(!1)}})}
function ql(){if(void 0!==nl)return nl;ak=!0;return nl=pl().then(function(a){ak=!1;var b;if(null!=(b=Wj())&&b.i){var c;b={hasSucceededOnce:(null==(c=Xj())?void 0:c.hasSucceededOnce)||a};var d;null==(d=Wj())||d.set("LAST_RESULT_ENTRY_KEY",b,2592E3,!0)}return a})}
function rl(){return A("ytglobal.idbToken_")||void 0}
function sl(){var a=rl();return a?Promise.resolve(a):ql().then(function(b){(b=b?ol:void 0)&&z("ytglobal.idbToken_",b);return b})}
;var tl=0;function ul(a,b){tl||(tl=gf.M(function(){var c,d,e,f,g;return w(function(h){switch(h.i){case 1:return t(h,sl(),2);case 2:c=h.j;if(!c)return h.return();d=!0;ua(h,3);return t(h,ll(a,c,b),5);case 5:e=h.j;if(!e.length){d=!1;h.u(6);break}f=e[0];return t(h,al(f.actualName),7);case 7:return t(h,il(f.actualName,c),6);case 6:xa(h,4);break;case 3:g=ya(h),fk(g),d=!1;case 4:gf.S(tl),tl=0,d&&ul(a,b),h.i=0}})}))}
function vl(){var a;return w(function(b){return 1==b.i?t(b,sl(),2):(a=b.j)?b.return(ml(a)):b.return(!1)})}
new Fd;function wl(a){if(!ik())throw a=new sk("AUTH_INVALID",{dbName:a}),fk(a),a;var b=jk();return{actualName:a+":"+b,publicName:a,userIdentifier:b}}
function xl(a,b,c,d){var e,f,g,h,k,m;return w(function(p){switch(p.i){case 1:return f=null!=(e=Error().stack)?e:"",t(p,sl(),2);case 2:g=p.j;if(!g)throw h=xk("openDbImpl",a,b),M("ytidb_async_stack_killswitch")||(h.stack=h.stack+"\n"+f.substring(f.indexOf("\n")+1)),fk(h),h;kk(a);k=c?{actualName:a,publicName:a,userIdentifier:void 0}:wl(a);ua(p,3);return t(p,hl(k,g),5);case 5:return t(p,$k(k.actualName,b,d),6);case 6:return p.return(p.j);case 3:return m=ya(p),ua(p,7),t(p,il(k.actualName,g),9);case 9:xa(p,
8);break;case 7:ya(p);case 8:throw m;}})}
function yl(a,b,c){c=void 0===c?{}:c;return xl(a,b,!1,c)}
function zl(a,b,c){c=void 0===c?{}:c;return xl(a,b,!0,c)}
function Al(a,b){b=void 0===b?{}:b;var c,d;return w(function(e){if(1==e.i)return t(e,sl(),2);if(3!=e.i){c=e.j;if(!c)return e.return();kk(a);d=wl(a);return t(e,al(d.actualName,b),3)}return t(e,il(d.actualName,c),0)})}
function Bl(a,b,c){a=a.map(function(d){return w(function(e){return 1==e.i?t(e,al(d.actualName,b),2):t(e,il(d.actualName,c),0)})});
return Promise.all(a).then(function(){})}
function Cl(){var a=void 0===a?{}:a;var b,c;return w(function(d){if(1==d.i)return t(d,sl(),2);if(3!=d.i){b=d.j;if(!b)return d.return();kk("LogsDatabaseV2");return t(d,kl(b),3)}c=d.j;return t(d,Bl(c,a,b),0)})}
function Dl(a,b){b=void 0===b?{}:b;var c;return w(function(d){if(1==d.i)return t(d,sl(),2);if(3!=d.i){c=d.j;if(!c)return d.return();kk(a);return t(d,al(a,b),3)}return t(d,il(a,c),0)})}
;function El(a){this.Ia=this.i=!1;this.potentialEsfErrorCounter=this.j=0;this.handleError=function(){};
this.qa=function(){};
this.now=Date.now;this.wa=!1;var b;this.Mb=null!=(b=a.Mb)?b:100;var c;this.Kb=null!=(c=a.Kb)?c:1;var d;this.Ib=null!=(d=a.Ib)?d:2592E6;var e;this.Gb=null!=(e=a.Gb)?e:12E4;var f;this.Jb=null!=(f=a.Jb)?f:5E3;var g;this.D=null!=(g=a.D)?g:void 0;this.Ma=!!a.Ma;var h;this.La=null!=(h=a.La)?h:.1;var k;this.Sa=null!=(k=a.Sa)?k:10;a.handleError&&(this.handleError=a.handleError);a.qa&&(this.qa=a.qa);a.wa&&(this.wa=a.wa);a.Ia&&(this.Ia=a.Ia);this.G=a.G;this.T=a.T;this.K=a.K;this.J=a.J;this.ba=a.ba;this.jb=
a.jb;this.ib=a.ib;Fl(this)&&(!this.G||this.G("networkless_logging"))&&Gl(this)}
function Gl(a){Fl(a)&&!a.wa&&(a.i=!0,a.Ma&&Math.random()<=a.La&&a.K.Tb(a.D),Hl(a),a.J.H()&&a.Ba(),a.J.U(a.jb,a.Ba.bind(a)),a.J.U(a.ib,a.pb.bind(a)))}
l=El.prototype;l.writeThenSend=function(a,b){var c=this;b=void 0===b?{}:b;if(Fl(this)&&this.i){var d={url:a,options:b,timestamp:this.now(),status:"NEW",sendCount:0};this.K.set(d,this.D).then(function(e){d.id=e;c.J.H()&&Il(c,d)}).catch(function(e){Il(c,d);
Jl(c,e)})}else this.ba(a,b)};
l.sendThenWrite=function(a,b,c){var d=this;b=void 0===b?{}:b;if(Fl(this)&&this.i){var e={url:a,options:b,timestamp:this.now(),status:"NEW",sendCount:0};this.G&&this.G("nwl_skip_retry")&&(e.skipRetry=c);if(this.J.H()||this.G&&this.G("nwl_aggressive_send_then_write")&&!e.skipRetry){if(!e.skipRetry){var f=b.onError?b.onError:function(){};
b.onError=function(g,h){return w(function(k){if(1==k.i)return t(k,d.K.set(e,d.D).catch(function(m){Jl(d,m)}),2);
f(g,h);k.i=0})}}this.ba(a,b,e.skipRetry)}else this.K.set(e,this.D).catch(function(g){d.ba(a,b,e.skipRetry);
Jl(d,g)})}else this.ba(a,b,this.G&&this.G("nwl_skip_retry")&&c)};
l.sendAndWrite=function(a,b){var c=this;b=void 0===b?{}:b;if(Fl(this)&&this.i){var d={url:a,options:b,timestamp:this.now(),status:"NEW",sendCount:0},e=!1,f=b.onSuccess?b.onSuccess:function(){};
d.options.onSuccess=function(g,h){void 0!==d.id?c.K.oa(d.id,c.D):e=!0;c.J.aa&&c.G&&c.G("vss_network_hint")&&c.J.aa(!0);f(g,h)};
this.ba(d.url,d.options);this.K.set(d,this.D).then(function(g){d.id=g;e&&c.K.oa(d.id,c.D)}).catch(function(g){Jl(c,g)})}else this.ba(a,b)};
l.Ba=function(){var a=this;if(!Fl(this))throw xk("throttleSend");this.j||(this.j=this.T.M(function(){var b;return w(function(c){if(1==c.i)return t(c,a.K.yb("NEW",a.D),2);if(3!=c.i)return b=c.j,b?t(c,Il(a,b),3):(a.pb(),c.return());a.j&&(a.j=0,a.Ba());c.i=0})},this.Mb))};
l.pb=function(){this.T.S(this.j);this.j=0};
function Il(a,b){var c,d;return w(function(e){switch(e.i){case 1:if(!Fl(a))throw c=xk("immediateSend"),c;if(void 0===b.id){e.u(2);break}return t(e,a.K.ec(b.id,a.D),3);case 3:(d=e.j)?b=d:a.qa(Error("The request cannot be found in the database."));case 2:if(Kl(a,b,a.Ib)){e.u(4);break}a.qa(Error("Networkless Logging: Stored logs request expired age limit"));if(void 0===b.id){e.u(5);break}return t(e,a.K.oa(b.id,a.D),5);case 5:return e.return();case 4:b.skipRetry||(b=Ll(a,b));if(!b){e.u(0);break}if(!b.skipRetry||
void 0===b.id){e.u(8);break}return t(e,a.K.oa(b.id,a.D),8);case 8:a.ba(b.url,b.options,!!b.skipRetry),e.i=0}})}
function Ll(a,b){if(!Fl(a))throw xk("updateRequestHandlers");var c=b.options.onError?b.options.onError:function(){};
b.options.onError=function(e,f){var g,h,k;return w(function(m){switch(m.i){case 1:g=Ml(f);if(!(a.G&&a.G("nwl_consider_error_code")&&g||a.G&&!a.G("nwl_consider_error_code")&&a.potentialEsfErrorCounter<=a.Sa)){m.u(2);break}if(!a.J.ca){m.u(3);break}return t(m,a.J.ca(),3);case 3:if(a.J.H()){m.u(2);break}c(e,f);if(!a.G||!a.G("nwl_consider_error_code")||void 0===(null==(h=b)?void 0:h.id)){m.u(6);break}return t(m,a.K.kb(b.id,a.D,!1),6);case 6:return m.return();case 2:if(a.G&&a.G("nwl_consider_error_code")&&
!g&&a.potentialEsfErrorCounter>a.Sa)return m.return();a.potentialEsfErrorCounter++;if(void 0===(null==(k=b)?void 0:k.id)){m.u(8);break}return b.sendCount<a.Kb?t(m,a.K.kb(b.id,a.D),12):t(m,a.K.oa(b.id,a.D),8);case 12:a.T.M(function(){a.J.H()&&a.Ba()},a.Jb);
case 8:c(e,f),m.i=0}})};
var d=b.options.onSuccess?b.options.onSuccess:function(){};
b.options.onSuccess=function(e,f){var g;return w(function(h){if(1==h.i)return void 0===(null==(g=b)?void 0:g.id)?h.u(2):t(h,a.K.oa(b.id,a.D),2);a.J.aa&&a.G&&a.G("vss_network_hint")&&a.J.aa(!0);d(e,f);h.i=0})};
return b}
function Kl(a,b,c){b=b.timestamp;return a.now()-b>=c?!1:!0}
function Hl(a){if(!Fl(a))throw xk("retryQueuedRequests");a.K.yb("QUEUED",a.D).then(function(b){b&&!Kl(a,b,a.Gb)?a.T.M(function(){return w(function(c){if(1==c.i)return void 0===b.id?c.u(2):t(c,a.K.kb(b.id,a.D),2);Hl(a);c.i=0})}):a.J.H()&&a.Ba()})}
function Jl(a,b){a.Ob&&!a.J.H()?a.Ob(b):a.handleError(b)}
function Fl(a){return!!a.D||a.Ia}
function Ml(a){var b;return(a=null==a?void 0:null==(b=a.error)?void 0:b.code)&&400<=a&&599>=a?!1:!0}
;function Nl(a,b){this.version=a;this.args=b}
;function Ol(a,b){this.topic=a;this.i=b}
Ol.prototype.toString=function(){return this.topic};var Pl=A("ytPubsub2Pubsub2Instance")||new J;J.prototype.subscribe=J.prototype.subscribe;J.prototype.unsubscribeByKey=J.prototype.ta;J.prototype.publish=J.prototype.ia;J.prototype.clear=J.prototype.clear;z("ytPubsub2Pubsub2Instance",Pl);var Ql=A("ytPubsub2Pubsub2SubscribedKeys")||{};z("ytPubsub2Pubsub2SubscribedKeys",Ql);var Rl=A("ytPubsub2Pubsub2TopicToKeys")||{};z("ytPubsub2Pubsub2TopicToKeys",Rl);var Sl=A("ytPubsub2Pubsub2IsAsync")||{};z("ytPubsub2Pubsub2IsAsync",Sl);
z("ytPubsub2Pubsub2SkipSubKey",null);function Tl(a,b){var c=Ul();c&&c.publish.call(c,a.toString(),a,b)}
function Vl(a){var b=Wl,c=Ul();if(!c)return 0;var d=c.subscribe(b.toString(),function(e,f){var g=A("ytPubsub2Pubsub2SkipSubKey");g&&g==d||(g=function(){if(Ql[d])try{if(f&&b instanceof Ol&&b!=e)try{var h=b.i,k=f;if(!k.args||!k.version)throw Error("yt.pubsub2.Data.deserialize(): serializedData is incomplete.");try{if(!h.ha){var m=new h;h.ha=m.version}var p=h.ha}catch(K){}if(!p||k.version!=p)throw Error("yt.pubsub2.Data.deserialize(): serializedData version is incompatible.");try{p=Reflect;var u=p.construct;
var x=k.args,v=x.length;if(0<v){var E=Array(v);for(k=0;k<v;k++)E[k]=x[k];var G=E}else G=[];f=u.call(p,h,G)}catch(K){throw K.message="yt.pubsub2.Data.deserialize(): "+K.message,K;}}catch(K){throw K.message="yt.pubsub2.pubsub2 cross-binary conversion error for "+b.toString()+": "+K.message,K;}a.call(window,f)}catch(K){ai(K)}},Sl[b.toString()]?A("yt.scheduler.instance")?gf.M(g):ui(g,0):g())});
Ql[d]=!0;Rl[b.toString()]||(Rl[b.toString()]=[]);Rl[b.toString()].push(d);return d}
function Xl(){var a=Yl,b=Vl(function(c){a.apply(void 0,arguments);Zl(b)});
return b}
function Zl(a){var b=Ul();b&&("number"===typeof a&&(a=[a]),db(a,function(c){b.unsubscribeByKey(c);delete Ql[c]}))}
function Ul(){return A("ytPubsub2Pubsub2Instance")}
;function $l(a,b){cl.call(this,a,b);this.options=b;kk(a)}
r($l,cl);function am(a,b){var c;return function(){c||(c=new $l(a,b));return c}}
$l.prototype.l=function(a,b,c){c=void 0===c?{}:c;return(this.options.lb?zl:yl)(a,b,Object.assign({},c))};
$l.prototype.delete=function(a){a=void 0===a?{}:a;return(this.options.lb?Dl:Al)(this.name,a)};
function bm(a,b){return am(a,b)}
;var cm;
function dm(){if(cm)return cm();var a={};cm=bm("LogsDatabaseV2",{ya:(a.LogsRequestsStore={Xa:2},a),lb:!1,upgrade:function(b,c,d){c(2)&&Mk(b,"LogsRequestsStore",{keyPath:"id",autoIncrement:!0});c(3);c(5)&&(d=d.objectStore("LogsRequestsStore"),d.i.indexNames.contains("newRequest")&&d.i.deleteIndex("newRequest"),d.i.createIndex("newRequestV2",["status","interface","timestamp"],{unique:!1}));c(7)&&b.i.objectStoreNames.contains("sapisid")&&b.i.deleteObjectStore("sapisid");c(9)&&b.i.objectStoreNames.contains("SWHealthLog")&&b.i.deleteObjectStore("SWHealthLog")},
version:9});return cm()}
;function em(a){return el(dm(),a)}
function fm(a,b){var c,d,e,f;return w(function(g){if(1==g.i)return c={startTime:P(),transactionType:"YT_IDB_TRANSACTION_TYPE_WRITE"},t(g,em(b),2);if(3!=g.i)return d=g.j,e=Object.assign({},a,{options:JSON.parse(JSON.stringify(a.options)),interface:L("INNERTUBE_CONTEXT_CLIENT_NAME",0)}),t(g,Ok(d,e),3);f=g.j;c.Ec=P();gm(c);return g.return(f)})}
function hm(a,b){var c,d,e,f,g,h,k;return w(function(m){if(1==m.i)return c={startTime:P(),transactionType:"YT_IDB_TRANSACTION_TYPE_READ"},t(m,em(b),2);if(3!=m.i)return d=m.j,e=L("INNERTUBE_CONTEXT_CLIENT_NAME",0),f=[a,e,0],g=[a,e,P()],h=IDBKeyRange.bound(f,g),k=void 0,t(m,Lk(d,["LogsRequestsStore"],{mode:"readwrite",O:!0},function(p){return Xk(p.objectStore("LogsRequestsStore").index("newRequestV2"),{query:h,direction:"prev"},function(u){u.getValue()&&(k=u.getValue(),"NEW"===a&&(k.status="QUEUED",
u.update(k)))})}),3);
c.Ec=P();gm(c);return m.return(k)})}
function im(a,b){var c;return w(function(d){if(1==d.i)return t(d,em(b),2);c=d.j;return d.return(Lk(c,["LogsRequestsStore"],{mode:"readwrite",O:!0},function(e){var f=e.objectStore("LogsRequestsStore");return f.get(a).then(function(g){if(g)return g.status="QUEUED",Ik(f.i.put(g,void 0)).then(function(){return g})})}))})}
function jm(a,b,c){c=void 0===c?!0:c;var d;return w(function(e){if(1==e.i)return t(e,em(b),2);d=e.j;return e.return(Lk(d,["LogsRequestsStore"],{mode:"readwrite",O:!0},function(f){var g=f.objectStore("LogsRequestsStore");return g.get(a).then(function(h){return h?(h.status="NEW",c&&(h.sendCount+=1),Ik(g.i.put(h,void 0)).then(function(){return h})):Bk.resolve(void 0)})}))})}
function km(a,b){var c;return w(function(d){if(1==d.i)return t(d,em(b),2);c=d.j;return d.return(c.delete("LogsRequestsStore",a))})}
function lm(a){var b,c;return w(function(d){if(1==d.i)return t(d,em(a),2);b=d.j;c=P()-2592E6;return t(d,Lk(b,["LogsRequestsStore"],{mode:"readwrite",O:!0},function(e){return Uk(e.objectStore("LogsRequestsStore"),{},function(f){if(f.getValue().timestamp<=c)return f.delete().then(function(){return f.continue()})})}),0)})}
function mm(){return w(function(a){return t(a,Cl(),0)})}
function gm(a){M("nwl_csi_killswitch")||.01>=Math.random()&&Tl("nwl_transaction_latency_payload",a)}
;var nm={},om=bm("ServiceWorkerLogsDatabase",{ya:(nm.SWHealthLog={Xa:1},nm),lb:!0,upgrade:function(a,b){b(1)&&Mk(a,"SWHealthLog",{keyPath:"id",autoIncrement:!0}).i.createIndex("swHealthNewRequest",["interface","timestamp"],{unique:!1})},
version:1});function pm(a){return el(om(),a)}
function qm(a){var b,c;return w(function(d){if(1==d.i)return t(d,pm(a),2);b=d.j;c=P()-2592E6;return t(d,Lk(b,["SWHealthLog"],{mode:"readwrite",O:!0},function(e){return Uk(e.objectStore("SWHealthLog"),{},function(f){if(f.getValue().timestamp<=c)return f.delete().then(function(){return f.continue()})})}),0)})}
function rm(a){var b;return w(function(c){if(1==c.i)return t(c,pm(a),2);b=c.j;return t(c,b.clear("SWHealthLog"),0)})}
;var sm={},tm=0;
function um(a){var b=void 0===b?"":b;var c=void 0===c?!1:c;if(a)if(b)Zi(a,void 0,"POST",b);else if(L("USE_NET_AJAX_FOR_PING_TRANSPORT",!1))Zi(a,void 0,"GET","",void 0,void 0,c);else{b:{try{var d=new $a({url:a});if(d.l&&d.j||d.m){var e=$b(ac(5,a)),f;if(!(f=!e||!e.endsWith("/aclk"))){var g=a.search(hc),h=gc(a,0,"ri",g);if(0>h)var k=null;else{var m=a.indexOf("&",h);if(0>m||m>g)m=g;k=decodeURIComponent(a.slice(h+3,-1!==m?m:0).replace(/\+/g," "))}f="1"!==k}var p=!f;break b}}catch(x){}p=!1}if(p){b:{try{if(window.navigator&&
window.navigator.sendBeacon&&window.navigator.sendBeacon(a,"")){var u=!0;break b}}catch(x){}u=!1}b=u?!0:!1}else b=!1;b||vm(a)}}
function vm(a){var b=new Image,c=""+tm++;sm[c]=b;b.onload=b.onerror=function(){delete sm[c]};
b.src=a}
;function wm(){this.i=new Map;this.j=!1}
function xm(){if(!wm.i){var a=A("yt.networkRequestMonitor.instance")||new wm;z("yt.networkRequestMonitor.instance",a);wm.i=a}return wm.i}
wm.prototype.requestComplete=function(a,b){b&&(this.j=!0);a=this.removeParams(a);this.i.get(a)||this.i.set(a,b)};
wm.prototype.isEndpointCFR=function(a){a=this.removeParams(a);return(a=this.i.get(a))?!1:!1===a&&this.j?!0:null};
wm.prototype.removeParams=function(a){return a.split("?")[0]};
wm.prototype.removeParams=wm.prototype.removeParams;wm.prototype.isEndpointCFR=wm.prototype.isEndpointCFR;wm.prototype.requestComplete=wm.prototype.requestComplete;wm.getInstance=xm;var ym;function zm(){ym||(ym=new Fj("yt.offline"));return ym}
function Am(a){if(M("offline_error_handling")){var b=zm().get("errors",!0)||{};b[a.message]={name:a.name,stack:a.stack};a.level&&(b[a.message].level=a.level);zm().set("errors",b,2592E3,!0)}}
function Bm(){if(M("offline_error_handling")){var a=zm().get("errors",!0);if(a){for(var b in a)if(a[b]){var c=new hk(b,"sent via offline_errors");c.name=a[b].name;c.stack=a[b].stack;c.level=a[b].level;ai(c)}zm().set("errors",{},2592E3,!0)}}}
;var Cm=Vh("network_polling_interval",3E4);function Dm(){$e.call(this);var a=this;this.R=0;this.B=this.o=!1;this.l=this.cb();M("use_shared_nsm")?(this.j=ff(),M("use_shared_nsm_and_keep_yt_online_updated")&&(this.j.U("networkstatus-online",function(){a.l=!0;a.B&&Bm()}),this.j.U("networkstatus-offline",function(){a.l=!1}))):(Em(this),Fm(this))}
r(Dm,$e);function Gm(){if(!Dm.i){var a=A("yt.networkStatusManager.instance")||new Dm;z("yt.networkStatusManager.instance",a);Dm.i=a}return Dm.i}
l=Dm.prototype;l.H=function(){if(M("use_shared_nsm")&&this.j){var a;return null==(a=this.j)?void 0:a.H()}return this.l};
l.aa=function(a){if(M("use_shared_nsm")&&this.j){var b;null!=(b=this.j)&&(b.j=a)}else a!==this.l&&(this.l=a)};
l.fc=function(a){!M("use_shared_nsm")&&(this.o=!0,void 0===a?0:a)&&(this.R||Hm(this))};
l.cb=function(){var a=window.navigator.onLine;return void 0===a?!0:a};
l.Wb=function(){this.B=!0};
l.U=function(a,b){return M("use_shared_nsm")&&this.j?this.j.U(a,b):$e.prototype.U.call(this,a,b)};
function Fm(a){window.addEventListener("online",function(){return w(function(b){if(1==b.i)return t(b,a.ca(),2);a.B&&Bm();b.i=0})})}
function Em(a){window.addEventListener("offline",function(){return w(function(b){return t(b,a.ca(),0)})})}
function Hm(a){a.R=Oj(function(){return w(function(b){if(1==b.i)return a.l?a.cb()||!a.o?b.u(3):t(b,a.ca(),3):t(b,a.ca(),3);Hm(a);b.i=0})},Cm)}
l.ca=function(a){var b=this;if(M("use_shared_nsm")&&this.j){var c=df(this.j,a);c.then(function(d){M("use_cfr_monitor")&&xm().requestComplete("generate_204",d)});
return c}return this.v?this.v:this.v=new Promise(function(d){var e,f,g,h;return w(function(k){switch(k.i){case 1:return e=window.AbortController?new window.AbortController:void 0,g=null==(f=e)?void 0:f.signal,h=!1,ua(k,2,3),e&&(b.N=gf.M(function(){e.abort()},a||2E4)),t(k,fetch("/generate_204",{method:"HEAD",
signal:g}),5);case 5:h=!0;case 3:za(k);M("use_cfr_monitor")&&xm().requestComplete("generate_204",h);b.v=void 0;b.N&&gf.S(b.N);h!==b.l&&(b.l=h,b.l&&b.o?af(b,"ytnetworkstatus-online"):b.o&&af(b,"ytnetworkstatus-offline"));d(h);Aa(k);break;case 2:ya(k),h=!1,k.u(3)}})})};
Dm.prototype.sendNetworkCheckRequest=Dm.prototype.ca;Dm.prototype.listen=Dm.prototype.U;Dm.prototype.enableErrorFlushing=Dm.prototype.Wb;Dm.prototype.getWindowStatus=Dm.prototype.cb;Dm.prototype.monitorNetworkStatusChange=Dm.prototype.fc;Dm.prototype.networkStatusHint=Dm.prototype.aa;Dm.prototype.isNetworkAvailable=Dm.prototype.H;Dm.getInstance=Gm;function Im(a){a=void 0===a?{}:a;$e.call(this);var b=this;this.l=this.N=0;this.o="ytnetworkstatus-offline";this.v="ytnetworkstatus-online";M("use_shared_nsm")&&(this.o="networkstatus-offline",this.v="networkstatus-online");this.j=Gm();var c=A("yt.networkStatusManager.instance.monitorNetworkStatusChange").bind(this.j);c&&c(a.vb);a.Db&&(c=A("yt.networkStatusManager.instance.enableErrorFlushing").bind(this.j))&&c();if(c=A("yt.networkStatusManager.instance.listen").bind(this.j))a.Ua?(this.Ua=a.Ua,c(this.v,
function(){Jm(b,"publicytnetworkstatus-online")}),c(this.o,function(){Jm(b,"publicytnetworkstatus-offline")})):(c(this.v,function(){af(b,"publicytnetworkstatus-online")}),c(this.o,function(){af(b,"publicytnetworkstatus-offline")}))}
r(Im,$e);Im.prototype.H=function(){var a=A("yt.networkStatusManager.instance.isNetworkAvailable");return a?a.bind(this.j)():!0};
Im.prototype.aa=function(a){var b=A("yt.networkStatusManager.instance.networkStatusHint").bind(this.j);b&&b(a)};
Im.prototype.ca=function(a){var b=this,c;return w(function(d){c=A("yt.networkStatusManager.instance.sendNetworkCheckRequest").bind(b.j);return M("skip_network_check_if_cfr")&&xm().isEndpointCFR("generate_204")?d.return(new Promise(function(e){var f;b.aa((null==(f=window.navigator)?void 0:f.onLine)||!0);e(b.H())})):c?d.return(c(a)):d.return(!0)})};
function Jm(a,b){a.Ua?a.l?(gf.S(a.N),a.N=gf.M(function(){a.B!==b&&(af(a,b),a.B=b,a.l=P())},a.Ua-(P()-a.l))):(af(a,b),a.B=b,a.l=P()):af(a,b)}
;var Km;function Lm(){El.call(this,{K:{Tb:lm,oa:km,yb:hm,ec:im,kb:jm,set:fm},J:Mm(),handleError:ai,qa:bi,ba:Nm,now:P,Ob:Am,T:Tj(),jb:"publicytnetworkstatus-online",ib:"publicytnetworkstatus-offline",Ma:!0,La:.1,Sa:Vh("potential_esf_error_limit",10),G:M,wa:!(ik()&&Om())});this.l=new Fd;M("networkless_immediately_drop_all_requests")&&mm();Dl("LogsDatabaseV2")}
r(Lm,El);function Pm(){var a=A("yt.networklessRequestController.instance");a||(a=new Lm,z("yt.networklessRequestController.instance",a),M("networkless_logging")&&sl().then(function(b){a.D=b;Gl(a);a.l.resolve();a.Ma&&Math.random()<=a.La&&a.D&&qm(a.D);M("networkless_immediately_drop_sw_health_store")&&Qm(a)}));
return a}
Lm.prototype.writeThenSend=function(a,b){b||(b={});ik()||(this.i=!1);El.prototype.writeThenSend.call(this,a,b)};
Lm.prototype.sendThenWrite=function(a,b,c){b||(b={});ik()||(this.i=!1);El.prototype.sendThenWrite.call(this,a,b,c)};
Lm.prototype.sendAndWrite=function(a,b){b||(b={});ik()||(this.i=!1);El.prototype.sendAndWrite.call(this,a,b)};
Lm.prototype.awaitInitialization=function(){return this.l.promise};
function Qm(a){var b;w(function(c){if(!a.D)throw b=xk("clearSWHealthLogsDb"),b;return c.return(rm(a.D).catch(function(d){a.handleError(d)}))})}
function Nm(a,b,c){M("use_cfr_monitor")&&Rm(a,b);var d;if(null==(d=b.postParams)?0:d.requestTimeMs)b.postParams.requestTimeMs=Math.round(P());c&&0===Object.keys(b).length?um(a):Wi(a,b)}
function Mm(){Km||(Km=new Im({Db:!0,vb:!0}));return Km}
function Rm(a,b){var c=b.onError?b.onError:function(){};
b.onError=function(e,f){xm().requestComplete(a,!1);c(e,f)};
var d=b.onSuccess?b.onSuccess:function(){};
b.onSuccess=function(e,f){xm().requestComplete(a,!0);d(e,f)}}
function Om(){return"www.youtube-nocookie.com"!==bc(document.location.toString())}
;var Sm=!1,Tm=0,Um=0,Vm,Wm=y.ytNetworklessLoggingInitializationOptions||{isNwlInitialized:Sm,potentialEsfErrorCounter:Um};z("ytNetworklessLoggingInitializationOptions",Wm);
function Xm(){var a;w(function(b){switch(b.i){case 1:return t(b,sl(),2);case 2:a=b.j;if(!a||!ik()&&!M("nwl_init_require_datasync_id_killswitch")||!Om()){b.u(0);break}Sm=!0;Wm.isNwlInitialized=Sm;if(!M("use_new_nwl_initialization")){b.u(4);break}return t(b,Pm().awaitInitialization(),5);case 5:return b.return();case 4:return t(b,Dl("LogsDatabaseV2"),6);case 6:if(!(.1>=Math.random())){b.u(7);break}return t(b,lm(a),8);case 8:return t(b,qm(a),7);case 7:Ym();Zm().H()&&$m();Zm().U("publicytnetworkstatus-online",
$m);Zm().U("publicytnetworkstatus-offline",an);if(!M("networkless_immediately_drop_sw_health_store")){b.u(10);break}return t(b,bn(),10);case 10:if(M("networkless_immediately_drop_all_requests"))return t(b,mm(),0);b.u(0)}})}
function cn(a,b){function c(d){var e=Zm().H();if(!dn()||!d||e&&M("vss_networkless_bypass_write"))en(a,b);else{var f={url:a,options:b,timestamp:P(),status:"NEW",sendCount:0};fm(f,d).then(function(g){f.id=g;Zm().H()&&fn(f)}).catch(function(g){fn(f);
Zm().H()?ai(g):Am(g)})}}
b=void 0===b?{}:b;M("skip_is_supported_killswitch")?sl().then(function(d){c(d)}):c(rl())}
function gn(a,b){function c(d){if(dn()&&d){var e={url:a,options:b,timestamp:P(),status:"NEW",sendCount:0},f=!1,g=b.onSuccess?b.onSuccess:function(){};
e.options.onSuccess=function(k,m){M("use_cfr_monitor")&&xm().requestComplete(e.url,!0);void 0!==e.id?km(e.id,d):f=!0;M("vss_network_hint")&&Zm().aa(!0);g(k,m)};
if(M("use_cfr_monitor")){var h=b.onError?b.onError:function(){};
e.options.onError=function(k,m){xm().requestComplete(e.url,!1);h(k,m)}}en(e.url,e.options);
fm(e,d).then(function(k){e.id=k;f&&km(e.id,d)}).catch(function(k){Zm().H()?ai(k):Am(k)})}else en(a,b)}
b=void 0===b?{}:b;M("skip_is_supported_killswitch")?sl().then(function(d){c(d)}):c(rl())}
function $m(){var a=rl();if(!a)throw xk("throttleSend");Tm||(Tm=gf.M(function(){var b;return w(function(c){if(1==c.i)return t(c,hm("NEW",a),2);if(3!=c.i)return b=c.j,b?t(c,fn(b),3):(an(),c.return());Tm&&(Tm=0,$m());c.i=0})},100))}
function an(){gf.S(Tm);Tm=0}
function fn(a){var b,c,d;return w(function(e){switch(e.i){case 1:b=rl();if(!b)throw c=xk("immediateSend"),c;if(void 0===a.id){e.u(2);break}return t(e,im(a.id,b),3);case 3:(d=e.j)?a=d:bi(Error("The request cannot be found in the database."));case 2:if(hn(a,2592E6)){e.u(4);break}bi(Error("Networkless Logging: Stored logs request expired age limit"));if(void 0===a.id){e.u(5);break}return t(e,km(a.id,b),5);case 5:return e.return();case 4:a.skipRetry||(a=jn(a));var f=a,g,h;if(null==f?0:null==(g=f.options)?
0:null==(h=g.postParams)?0:h.requestTimeMs)f.options.postParams.requestTimeMs=Math.round(P());a=f;if(!a){e.u(0);break}if(!a.skipRetry||void 0===a.id){e.u(8);break}return t(e,km(a.id,b),8);case 8:en(a.url,a.options,!!a.skipRetry),e.i=0}})}
function jn(a){var b=rl();if(!b)throw xk("updateRequestHandlers");var c=a.options.onError?a.options.onError:function(){};
a.options.onError=function(e,f){var g,h,k;return w(function(m){switch(m.i){case 1:M("use_cfr_monitor")&&xm().requestComplete(a.url,!1);g=Ml(f);if(!(M("nwl_consider_error_code")&&g||!M("nwl_consider_error_code")&&kn()<=Vh("potential_esf_error_limit",10))){m.u(2);break}if(M("skip_checking_network_on_cfr_failure")&&(!M("skip_checking_network_on_cfr_failure")||xm().isEndpointCFR(a.url))){m.u(3);break}return t(m,Zm().ca(),3);case 3:if(Zm().H()){m.u(2);break}c(e,f);if(!M("nwl_consider_error_code")||void 0===
(null==(h=a)?void 0:h.id)){m.u(6);break}return t(m,jm(a.id,b,!1),6);case 6:return m.return();case 2:if(M("nwl_consider_error_code")&&!g&&kn()>Vh("potential_esf_error_limit",10))return m.return();A("ytNetworklessLoggingInitializationOptions")&&Wm.potentialEsfErrorCounter++;Um++;if(void 0===(null==(k=a)?void 0:k.id)){m.u(8);break}return 1>a.sendCount?t(m,jm(a.id,b),12):t(m,km(a.id,b),8);case 12:gf.M(function(){Zm().H()&&$m()},5E3);
case 8:c(e,f),m.i=0}})};
var d=a.options.onSuccess?a.options.onSuccess:function(){};
a.options.onSuccess=function(e,f){var g;return w(function(h){if(1==h.i)return M("use_cfr_monitor")&&xm().requestComplete(a.url,!0),void 0===(null==(g=a)?void 0:g.id)?h.u(2):t(h,km(a.id,b),2);M("vss_network_hint")&&Zm().aa(!0);d(e,f);h.i=0})};
return a}
function hn(a,b){a=a.timestamp;return P()-a>=b?!1:!0}
function Ym(){var a=rl();if(!a)throw xk("retryQueuedRequests");hm("QUEUED",a).then(function(b){b&&!hn(b,12E4)?gf.M(function(){return w(function(c){if(1==c.i)return void 0===b.id?c.u(2):t(c,jm(b.id,a),2);Ym();c.i=0})}):Zm().H()&&$m()})}
function bn(){var a,b;return w(function(c){a=rl();if(!a)throw b=xk("clearSWHealthLogsDb"),b;return c.return(rm(a).catch(function(d){ai(d)}))})}
function Zm(){if(M("use_new_nwl"))return Mm();Vm||(Vm=new Im({Db:!0,vb:!0}));return Vm}
function en(a,b,c){c&&0===Object.keys(b).length?um(a):Wi(a,b)}
function dn(){return A("ytNetworklessLoggingInitializationOptions")?Wm.isNwlInitialized:Sm}
function kn(){return A("ytNetworklessLoggingInitializationOptions")?Wm.potentialEsfErrorCounter:Um}
;function ln(a){var b=this;this.config_=null;a?this.config_=a:vj()&&(this.config_=wj());Oj(function(){Lj(b)},5E3)}
ln.prototype.isReady=function(){!this.config_&&vj()&&(this.config_=wj());return!!this.config_};
function Mj(a,b,c,d){function e(E){E=void 0===E?!1:E;var G;if(d.retry&&"www.youtube-nocookie.com"!=h&&(E||M("skip_ls_gel_retry")||"application/json"!==g.headers["Content-Type"]||(G=Jj(b,c,m,k)),G)){var K=g.onSuccess,N=g.onFetchSuccess;g.onSuccess=function(O,S){Kj(G);K(O,S)};
c.onFetchSuccess=function(O,S){Kj(G);N(O,S)}}try{E&&d.retry&&!d.Eb.bypassNetworkless?(g.method="POST",d.Eb.writeThenSend?M("use_new_nwl_wts")?Pm().writeThenSend(v,g):cn(v,g):M("use_new_nwl_saw")?Pm().sendAndWrite(v,g):gn(v,g)):(g.method="POST",g.postParams||(g.postParams={}),Wi(v,g))}catch(O){if("InvalidAccessError"==O.name)G&&(Kj(G),G=0),bi(Error("An extension is blocking network request."));
else throw O;}G&&Oj(function(){Lj(a)},5E3)}
!L("VISITOR_DATA")&&"visitor_id"!==b&&.01>Math.random()&&bi(new hk("Missing VISITOR_DATA when sending innertube request.",b,c,d));if(!a.isReady()){var f=new hk("innertube xhrclient not ready",b,c,d);ai(f);throw f;}var g={headers:d.headers||{},method:"POST",postParams:c,postBody:d.postBody,postBodyFormat:d.postBodyFormat||"JSON",onTimeout:function(){d.onTimeout()},
onFetchTimeout:d.onTimeout,onSuccess:function(E,G){if(d.onSuccess)d.onSuccess(G)},
onFetchSuccess:function(E){if(d.onSuccess)d.onSuccess(E)},
onError:function(E,G){if(d.onError)d.onError(G)},
onFetchError:function(E){if(d.onError)d.onError(E)},
timeout:d.timeout,withCredentials:!0};g.headers["Content-Type"]||(g.headers["Content-Type"]="application/json");var h="";(f=a.config_.ac)&&(h=f);var k=a.config_.dc||!1,m=Dj(k,h,d);Object.assign(g.headers,m);(f=g.headers.Authorization)&&!h&&(g.headers["x-origin"]=window.location.origin);var p="/youtubei/"+a.config_.innertubeApiVersion+"/"+b,u={alt:"json"},x=a.config_.cc&&f;x=x&&f.startsWith("Bearer");x||(u.key=a.config_.innertubeApiKey);var v=ni(""+h+p,u||{},!0);M("use_new_nwl")&&Pm().i||!M("use_new_nwl")&&
dn()?ql().then(function(E){e(E)}):e(!1)}
;var mn={appSettingsCaptured:!0,visualElementAttached:!0,visualElementGestured:!0,visualElementHidden:!0,visualElementShown:!0,flowEvent:!0,visualElementStateChanged:!0,playbackAssociated:!0,youThere:!0,accountStateChangeSignedIn:!0,accountStateChangeSignedOut:!0},nn={latencyActionBaselined:!0,latencyActionInfo:!0,latencyActionTicked:!0,bedrockRepetitiveActionTimed:!0,adsClientStateChange:!0,streamzIncremented:!0,mdxDialAdditionalDataUpdateEvent:!0,tvhtml5WatchKeyEvent:!0,tvhtml5VideoSeek:!0,tokenRefreshEvent:!0,
adNotify:!0,adNotifyFilled:!0,tvhtml5LaunchUrlComponentChanged:!0,bedrockResourceConsumptionSnapshot:!0,deviceStartupMetrics:!0,mdxSignIn:!0,tvhtml5KeyboardLogging:!0,tvhtml5StartupSoundEvent:!0,tvhtml5LiveChatStatus:!0,tvhtml5DeviceStorageStatus:!0,tvhtml5LocalStorage:!0,directSignInEvent:!0,finalPayload:!0,tvhtml5SearchCompleted:!0,tvhtml5KeyboardPerformance:!0,adNotifyFailure:!0,latencyActionSpan:!0,tvhtml5AccountDialogOpened:!0,tvhtml5ApiTest:!0};var on=0,pn=vc?"webkit":uc?"moz":sc?"ms":rc?"o":"";z("ytDomDomGetNextId",A("ytDomDomGetNextId")||function(){return++on});var qn={stopImmediatePropagation:1,stopPropagation:1,preventMouseEvent:1,preventManipulation:1,preventDefault:1,layerX:1,layerY:1,screenX:1,screenY:1,scale:1,rotation:1,webkitMovementX:1,webkitMovementY:1};
function rn(a){this.type="";this.state=this.source=this.data=this.currentTarget=this.relatedTarget=this.target=null;this.charCode=this.keyCode=0;this.metaKey=this.shiftKey=this.ctrlKey=this.altKey=!1;this.rotation=this.clientY=this.clientX=0;this.scale=1;this.changedTouches=this.touches=null;try{if(a=a||window.event){this.event=a;for(var b in a)b in qn||(this[b]=a[b]);this.scale=a.scale;this.rotation=a.rotation;var c=a.target||a.srcElement;c&&3==c.nodeType&&(c=c.parentNode);this.target=c;var d=a.relatedTarget;
if(d)try{d=d.nodeName?d:null}catch(e){d=null}else"mouseover"==this.type?d=a.fromElement:"mouseout"==this.type&&(d=a.toElement);this.relatedTarget=d;this.clientX=void 0!=a.clientX?a.clientX:a.pageX;this.clientY=void 0!=a.clientY?a.clientY:a.pageY;this.keyCode=a.keyCode?a.keyCode:a.which;this.charCode=a.charCode||("keypress"==this.type?this.keyCode:0);this.altKey=a.altKey;this.ctrlKey=a.ctrlKey;this.shiftKey=a.shiftKey;this.metaKey=a.metaKey;this.i=a.pageX;this.j=a.pageY}}catch(e){}}
function sn(a){if(document.body&&document.documentElement){var b=document.body.scrollTop+document.documentElement.scrollTop;a.i=a.clientX+(document.body.scrollLeft+document.documentElement.scrollLeft);a.j=a.clientY+b}}
rn.prototype.preventDefault=function(){this.event&&(this.event.returnValue=!1,this.event.preventDefault&&this.event.preventDefault())};
rn.prototype.stopPropagation=function(){this.event&&(this.event.cancelBubble=!0,this.event.stopPropagation&&this.event.stopPropagation())};
rn.prototype.stopImmediatePropagation=function(){this.event&&(this.event.cancelBubble=!0,this.event.stopImmediatePropagation&&this.event.stopImmediatePropagation())};var mb=y.ytEventsEventsListeners||{};z("ytEventsEventsListeners",mb);var tn=y.ytEventsEventsCounter||{count:0};z("ytEventsEventsCounter",tn);
function un(a,b,c,d){d=void 0===d?{}:d;a.addEventListener&&("mouseenter"!=b||"onmouseenter"in document?"mouseleave"!=b||"onmouseenter"in document?"mousewheel"==b&&"MozBoxSizing"in document.documentElement.style&&(b="MozMousePixelScroll"):b="mouseout":b="mouseover");return lb(function(e){var f="boolean"===typeof e[4]&&e[4]==!!d,g=Pa(e[4])&&Pa(d)&&qb(e[4],d);return!!e.length&&e[0]==a&&e[1]==b&&e[2]==c&&(f||g)})}
var vn=bb(function(){var a=!1;try{var b=Object.defineProperty({},"capture",{get:function(){a=!0}});
window.addEventListener("test",null,b)}catch(c){}return a});
function wn(a,b,c,d){d=void 0===d?{}:d;if(!a||!a.addEventListener&&!a.attachEvent)return"";var e=un(a,b,c,d);if(e)return e;e=++tn.count+"";var f=!("mouseenter"!=b&&"mouseleave"!=b||!a.addEventListener||"onmouseenter"in document);var g=f?function(h){h=new rn(h);if(!Sd(h.relatedTarget,function(k){return k==a}))return h.currentTarget=a,h.type=b,c.call(a,h)}:function(h){h=new rn(h);
h.currentTarget=a;return c.call(a,h)};
g=$h(g);a.addEventListener?("mouseenter"==b&&f?b="mouseover":"mouseleave"==b&&f?b="mouseout":"mousewheel"==b&&"MozBoxSizing"in document.documentElement.style&&(b="MozMousePixelScroll"),vn()||"boolean"===typeof d?a.addEventListener(b,g,d):a.addEventListener(b,g,!!d.capture)):a.attachEvent("on"+b,g);mb[e]=[a,b,c,g,d];return e}
function xn(a){a&&("string"==typeof a&&(a=[a]),db(a,function(b){if(b in mb){var c=mb[b],d=c[0],e=c[1],f=c[3];c=c[4];d.removeEventListener?vn()||"boolean"===typeof c?d.removeEventListener(e,f,c):d.removeEventListener(e,f,!!c.capture):d.detachEvent&&d.detachEvent("on"+e,f);delete mb[b]}}))}
;var yn=window.ytcsi&&window.ytcsi.now?window.ytcsi.now:window.performance&&window.performance.timing&&window.performance.now&&window.performance.timing.navigationStart?function(){return window.performance.timing.navigationStart+window.performance.now()}:function(){return(new Date).getTime()};function zn(a){this.L=a;this.j=null;this.o=0;this.B=null;this.v=0;this.l=[];for(a=0;4>a;a++)this.l.push(0);this.m=0;this.R=wn(window,"mousemove",Va(this.W,this));a=Va(this.N,this);"function"===typeof a&&(a=$h(a));this.ea=window.setInterval(a,25)}
Xa(zn,I);zn.prototype.W=function(a){void 0===a.i&&sn(a);var b=a.i;void 0===a.j&&sn(a);this.j=new Od(b,a.j)};
zn.prototype.N=function(){if(this.j){var a=yn();if(0!=this.o){var b=this.B,c=this.j,d=b.x-c.x;b=b.y-c.y;d=Math.sqrt(d*d+b*b)/(a-this.o);this.l[this.m]=.5<Math.abs((d-this.v)/this.v)?1:0;for(c=b=0;4>c;c++)b+=this.l[c]||0;3<=b&&this.L();this.v=d}this.o=a;this.B=this.j;this.m=(this.m+1)%4}};
zn.prototype.I=function(){window.clearInterval(this.ea);xn(this.R)};var An={};
function Bn(a){var b=void 0===a?{}:a;a=void 0===b.jc?!1:b.jc;b=void 0===b.Xb?!0:b.Xb;if(null==A("_lact",window)){var c=parseInt(L("LACT"),10);c=isFinite(c)?Date.now()-Math.max(c,0):-1;z("_lact",c,window);z("_fact",c,window);-1==c&&Cn();wn(document,"keydown",Cn);wn(document,"keyup",Cn);wn(document,"mousedown",Cn);wn(document,"mouseup",Cn);a?wn(window,"touchmove",function(){Dn("touchmove",200)},{passive:!0}):(wn(window,"resize",function(){Dn("resize",200)}),b&&wn(window,"scroll",function(){Dn("scroll",200)}));
new zn(function(){Dn("mouse",100)});
wn(document,"touchstart",Cn,{passive:!0});wn(document,"touchend",Cn,{passive:!0})}}
function Dn(a,b){An[a]||(An[a]=!0,gf.M(function(){Cn();An[a]=!1},b))}
function Cn(){null==A("_lact",window)&&Bn();var a=Date.now();z("_lact",a,window);-1==A("_fact",window)&&z("_fact",a,window);(a=A("ytglobal.ytUtilActivityCallback_"))&&a()}
function En(){var a=A("_lact",window);return null==a?-1:Math.max(Date.now()-a,0)}
;var Fn=y.ytPubsubPubsubInstance||new J,Gn=y.ytPubsubPubsubSubscribedKeys||{},Hn=y.ytPubsubPubsubTopicToKeys||{},In=y.ytPubsubPubsubIsSynchronous||{};function Jn(a,b){var c=Kn();if(c&&b){var d=c.subscribe(a,function(){var e=arguments;var f=function(){Gn[d]&&b.apply&&"function"==typeof b.apply&&b.apply(window,e)};
try{In[a]?f():ui(f,0)}catch(g){ai(g)}},void 0);
Gn[d]=!0;Hn[a]||(Hn[a]=[]);Hn[a].push(d);return d}return 0}
function Ln(a){var b=Kn();b&&("number"===typeof a?a=[a]:"string"===typeof a&&(a=[parseInt(a,10)]),db(a,function(c){b.unsubscribeByKey(c);delete Gn[c]}))}
function Mn(a,b){var c=Kn();c&&c.publish.apply(c,arguments)}
function Nn(a){var b=Kn();if(b)if(b.clear(a),a)On(a);else for(var c in Hn)On(c)}
function Kn(){return y.ytPubsubPubsubInstance}
function On(a){Hn[a]&&(a=Hn[a],db(a,function(b){Gn[b]&&delete Gn[b]}),a.length=0)}
J.prototype.subscribe=J.prototype.subscribe;J.prototype.unsubscribeByKey=J.prototype.ta;J.prototype.publish=J.prototype.ia;J.prototype.clear=J.prototype.clear;z("ytPubsubPubsubInstance",Fn);z("ytPubsubPubsubTopicToKeys",Hn);z("ytPubsubPubsubIsSynchronous",In);z("ytPubsubPubsubSubscribedKeys",Gn);var Pn=Vh("initial_gel_batch_timeout",2E3),go=Math.pow(2,16)-1,Fo=void 0;function Go(){this.l=this.i=this.j=0}
var Ho=new Go,Io=new Go,Jo=!0,Ko=y.ytLoggingTransportGELQueue_||new Map;z("ytLoggingTransportGELQueue_",Ko);var Lo=y.ytLoggingTransportGELProtoQueue_||new Map;z("ytLoggingTransportGELProtoQueue_",Lo);var Mo=y.ytLoggingTransportTokensToCttTargetIds_||{};z("ytLoggingTransportTokensToCttTargetIds_",Mo);var No=y.ytLoggingTransportTokensToJspbCttTargetIds_||{};z("ytLoggingTransportTokensToJspbCttTargetIds_",No);
function Oo(a,b){if("log_event"===a.endpoint){var c=Po(a),d=Ko.get(c)||[];Ko.set(c,d);d.push(a.payload);Qo(b,d,c)}}
function Ro(a,b){if("log_event"===a.endpoint){var c=Po(a,!0),d=Lo.get(c)||[];Lo.set(c,d);a=a.payload.toJSON();d.push(a);Qo(b,d,c,!0)}}
function Qo(a,b,c,d){d=void 0===d?!1:d;a&&(Fo=new a);a=Vh("tvhtml5_logging_max_batch")||Vh("web_logging_max_batch")||100;var e=P(),f=d?Io.l:Ho.l;b.length>=a?So({writeThenSend:!0},M("flush_only_full_queue")?c:void 0,d):10<=e-f&&(To(d),d?Io.l=e:Ho.l=e)}
function Uo(a,b){if("log_event"===a.endpoint){var c=Po(a),d=new Map;d.set(c,[a.payload]);b&&(Fo=new b);return new ag(function(e,f){Fo&&Fo.isReady()?Vo(d,e,f,{bypassNetworkless:!0},!0):e()})}}
function Wo(a,b){if("log_event"===a.endpoint){var c=Po(a,!0),d=new Map;d.set(c,[a.payload.toJSON()]);b&&(Fo=new b);return new ag(function(e){Fo&&Fo.isReady()?Xo(d,e,{bypassNetworkless:!0},!0):e()})}}
function Po(a,b){var c="";if(a.va)c="visitorOnlyApprovedKey";else if(a.cttAuthInfo){if(void 0===b?0:b){b=a.cttAuthInfo.token;c=a.cttAuthInfo;var d=new Jh;c.videoId?d.setVideoId(c.videoId):c.playlistId&&qd(d,2,Kh,c.playlistId);No[b]=d}else b=a.cttAuthInfo,c={},b.videoId?c.videoId=b.videoId:b.playlistId&&(c.playlistId=b.playlistId),Mo[a.cttAuthInfo.token]=c;c=a.cttAuthInfo.token}return c}
function So(a,b,c){a=void 0===a?{}:a;c=void 0===c?!1:c;new ag(function(d,e){c?(vi(Io.j),vi(Io.i),Io.i=0):(vi(Ho.j),vi(Ho.i),Ho.i=0);if(Fo&&Fo.isReady())if(void 0!==b)if(c){e=new Map;var f=Lo.get(b)||[];e.set(b,f);Xo(e,d,a);Lo.delete(b)}else{f=new Map;var g=Ko.get(b)||[];f.set(b,g);Vo(f,d,e,a);Ko.delete(b)}else c?(Xo(Lo,d,a),Lo.clear()):(Vo(Ko,d,e,a),Ko.clear());else To(c),d()})}
function To(a){a=void 0===a?!1:a;if(M("web_gel_timeout_cap")&&(!a&&!Ho.i||a&&!Io.i)){var b=ui(function(){So({writeThenSend:!0},void 0,a)},6E4);
a?Io.i=b:Ho.i=b}vi(a?Io.j:Ho.j);b=L("LOGGING_BATCH_TIMEOUT",Vh("web_gel_debounce_ms",1E4));M("shorten_initial_gel_batch_timeout")&&Jo&&(b=Pn);b=ui(function(){So({writeThenSend:!0},void 0,a)},b);
a?Io.j=b:Ho.j=b}
function Vo(a,b,c,d,e){var f=Fo;d=void 0===d?{}:d;var g=Math.round(P()),h=a.size;a=q(a);for(var k=a.next();!k.done;k=a.next()){var m=q(k.value);k=m.next().value;var p=m.next().value;m=k;k=ub({context:xj(f.config_||wj())});k.events=p;(p=Mo[m])&&Yo(k,m,p);delete Mo[m];m="visitorOnlyApprovedKey"===m;Zo(k,g,m);$o(d);p=function(){h--;h||b()};
var u=function(){h--;h||b()};
try{Mj(f,"log_event",k,ap(d,m,p,u,e)),Jo=!1}catch(x){ai(x),c()}}}
function Xo(a,b,c,d){var e=Fo;c=void 0===c?{}:c;var f=Math.round(P()),g=a.size;a=q(a);for(var h=a.next();!h.done;h=a.next()){var k=q(h.value);h=k.next().value;var m=k=k.next().value;k=new Lh;var p=Cj(e.config_||wj());D(k,1,p);m=bp(m);for(p=0;p<m.length;p++)vd(k,3,Fh,m[p]);(m=No[h])&&cp(k,h,m);delete No[h];h="visitorOnlyApprovedKey"===h;dp(k,f,h);$o(c);a:{ad=!0;try{var u=JSON.stringify(k.toJSON(),Ad);break a}finally{ad=!1}u=void 0}k=u;h=ap(c,h,function(){g--;g||b()},function(){g--;
g||b()},d);
h.headers={"Content-Type":"application/json+protobuf"};h.postBodyFormat="JSPB";h.postBody=k;Mj(e,"log_event","",h);Jo=!1}}
function $o(a){M("always_send_and_write")&&(a.writeThenSend=!1)}
function ap(a,b,c,d,e){return{retry:!0,onSuccess:c,onError:d,Eb:a,va:b,np:!!e,headers:{},postBodyFormat:"",postBody:""}}
function Zo(a,b,c){a.requestTimeMs=String(b);M("unsplit_gel_payloads_in_logs")&&(a.unsplitGelPayloadsInLogs=!0);!c&&(b=L("EVENT_ID"))&&(c=ep(),a.serializedClientEventId={serializedEventId:b,clientCounter:String(c)})}
function dp(a,b,c){C(a,2,b);if(!c&&(b=L("EVENT_ID"))){c=ep();var d=new Ih;C(d,1,b);C(d,2,c);D(a,5,d)}}
function ep(){var a=L("BATCH_CLIENT_COUNTER")||0;a||(a=Math.floor(Math.random()*go/2));a++;a>go&&(a=1);Sh("BATCH_CLIENT_COUNTER",a);return a}
function Yo(a,b,c){if(c.videoId)var d="VIDEO";else if(c.playlistId)d="PLAYLIST";else return;a.credentialTransferTokenTargetId=c;a.context=a.context||{};a.context.user=a.context.user||{};a.context.user.credentialTransferTokens=[{token:b,scope:d}]}
function cp(a,b,c){if(od(c,1===rd(c,Kh)?1:-1))var d=1;else if(c.getPlaylistId())d=2;else return;D(a,4,c);a=sd(a,Ug,1)||new Ug;c=sd(a,Sg,3)||new Sg;var e=new Rg;e.setToken(b);C(e,1,d);vd(c,12,Rg,e);D(a,3,c)}
function bp(a){for(var b=[],c=0;c<a.length;c++)try{b.push(new Fh(a[c]))}catch(d){ai(new hk("Transport failed to deserialize "+String(a[c])))}return b}
;var fp=y.ytLoggingGelSequenceIdObj_||{};z("ytLoggingGelSequenceIdObj_",fp);
function gp(a,b,c,d){d=void 0===d?{}:d;if(M("lr_drop_other_and_business_payloads")){if(nn[a]||mn[a])return}else if(M("lr_drop_other_payloads")&&nn[a])return;var e={},f=Math.round(d.timestamp||P());e.eventTimeMs=f<Number.MAX_SAFE_INTEGER?f:0;e[a]=b;a=En();e.context={lastActivityMs:String(d.timestamp||!isFinite(a)?-1:a)};M("log_sequence_info_on_gel_web")&&d.V&&(a=e.context,b=d.V,b={index:hp(b),groupKey:b},a.sequence=b,d.wb&&delete fp[d.V]);(d.sc?Uo:Oo)({endpoint:"log_event",payload:e,cttAuthInfo:d.cttAuthInfo,
va:d.va},c)}
function ip(a){So(void 0,void 0,void 0===a?!1:a)}
function hp(a){fp[a]=a in fp?fp[a]+1:0;return fp[a]}
;function ek(a,b,c){c=void 0===c?{}:c;var d=ln;L("ytLoggingEventsDefaultDisabled",!1)&&ln==ln&&(d=null);gp(a,b,d,c)}
;var jp=[{hb:function(a){return"Cannot read property '"+a.key+"'"},
Ra:{Error:[{regexp:/(Permission denied) to access property "([^']+)"/,groups:["reason","key"]}],TypeError:[{regexp:/Cannot read property '([^']+)' of (null|undefined)/,groups:["key","value"]},{regexp:/\u65e0\u6cd5\u83b7\u53d6\u672a\u5b9a\u4e49\u6216 (null|undefined) \u5f15\u7528\u7684\u5c5e\u6027\u201c([^\u201d]+)\u201d/,groups:["value","key"]},{regexp:/\uc815\uc758\ub418\uc9c0 \uc54a\uc74c \ub610\ub294 (null|undefined) \ucc38\uc870\uc778 '([^']+)' \uc18d\uc131\uc744 \uac00\uc838\uc62c \uc218 \uc5c6\uc2b5\ub2c8\ub2e4./,
groups:["value","key"]},{regexp:/No se puede obtener la propiedad '([^']+)' de referencia nula o sin definir/,groups:["key"]},{regexp:/Unable to get property '([^']+)' of (undefined or null) reference/,groups:["key","value"]},{regexp:/(null) is not an object \(evaluating '(?:([^.]+)\.)?([^']+)'\)/,groups:["value","base","key"]}]}},{hb:function(a){return"Cannot call '"+a.key+"'"},
Ra:{TypeError:[{regexp:/(?:([^ ]+)?\.)?([^ ]+) is not a function/,groups:["base","key"]},{regexp:/([^ ]+) called on (null or undefined)/,groups:["key","value"]},{regexp:/Object (.*) has no method '([^ ]+)'/,groups:["base","key"]},{regexp:/Object doesn't support property or method '([^ ]+)'/,groups:["key"]},{regexp:/\u30aa\u30d6\u30b8\u30a7\u30af\u30c8\u306f '([^']+)' \u30d7\u30ed\u30d1\u30c6\u30a3\u307e\u305f\u306f\u30e1\u30bd\u30c3\u30c9\u3092\u30b5\u30dd\u30fc\u30c8\u3057\u3066\u3044\u307e\u305b\u3093/,
groups:["key"]},{regexp:/\uac1c\uccb4\uac00 '([^']+)' \uc18d\uc131\uc774\ub098 \uba54\uc11c\ub4dc\ub97c \uc9c0\uc6d0\ud558\uc9c0 \uc54a\uc2b5\ub2c8\ub2e4./,groups:["key"]}]}},{hb:function(a){return a.key+" is not defined"},
Ra:{ReferenceError:[{regexp:/(.*) is not defined/,groups:["key"]},{regexp:/Can't find variable: (.*)/,groups:["key"]}]}}];var lp={ga:[],fa:[{ka:kp,weight:500}]};function kp(a){if("JavaException"===a.name)return!0;a=a.stack;return a.includes("chrome://")||a.includes("chrome-extension://")||a.includes("moz-extension://")}
;function mp(){this.fa=[];this.ga=[]}
var np;function op(){if(!np){var a=np=new mp;a.ga.length=0;a.fa.length=0;lp.ga&&a.ga.push.apply(a.ga,lp.ga);lp.fa&&a.fa.push.apply(a.fa,lp.fa)}return np}
;var pp=new J;function qp(a){function b(){return a.charCodeAt(d++)}
var c=a.length,d=0;do{var e=rp(b);if(Infinity===e)break;var f=e>>3;switch(e&7){case 0:e=rp(b);if(2===f)return e;break;case 1:if(2===f)return;d+=8;break;case 2:e=rp(b);if(2===f)return a.substr(d,e);d+=e;break;case 5:if(2===f)return;d+=4;break;default:return}}while(d<c)}
function rp(a){var b=a(),c=b&127;if(128>b)return c;b=a();c|=(b&127)<<7;if(128>b)return c;b=a();c|=(b&127)<<14;if(128>b)return c;b=a();return 128>b?c|(b&127)<<21:Infinity}
;function sp(a,b,c,d){if(a)if(Array.isArray(a)){var e=d;for(d=0;d<a.length&&!(a[d]&&(e+=tp(d,a[d],b,c),500<e));d++);d=e}else if("object"===typeof a)for(e in a){if(a[e]){var f=a[e];var g=b;var h=c;g="string"!==typeof f||"clickTrackingParams"!==e&&"trackingParams"!==e?0:(f=qp(atob(f.replace(/-/g,"+").replace(/_/g,"/"))))?tp(e+".ve",f,g,h):0;d+=g;d+=tp(e,a[e],b,c);if(500<d)break}}else c[b]=up(a),d+=c[b].length;else c[b]=up(a),d+=c[b].length;return d}
function tp(a,b,c,d){c+="."+a;a=up(b);d[c]=a;return c.length+a.length}
function up(a){try{return("string"===typeof a?a:String(JSON.stringify(a))).substr(0,500)}catch(b){return"unable to serialize "+typeof a+" ("+b.message+")"}}
;var vp=y.ytLoggingGelSequenceIdObj_||{};z("ytLoggingGelSequenceIdObj_",vp);function wp(a,b,c){c=void 0===c?{}:c;var d=Math.round(c.timestamp||P());C(a,1,d<Number.MAX_SAFE_INTEGER?d:0);var e=En();d=new Eh;C(d,1,c.timestamp||!isFinite(e)?-1:e);if(M("log_sequence_info_on_gel_web")&&c.V){e=c.V;var f=hp(e),g=new Dh;C(g,2,f);C(g,1,e);D(d,3,g);c.wb&&delete vp[c.V]}D(a,33,d);(c.sc?Wo:Ro)({endpoint:"log_event",payload:a,cttAuthInfo:c.cttAuthInfo,va:c.va},b)}
;function xp(a,b){b=void 0===b?{}:b;var c=!1;L("ytLoggingEventsDefaultDisabled",!1)&&ln===ln&&(c=!0);wp(a,c?null:ln,b)}
;function yp(a,b,c){var d=new Fh;ud(d,73,Gh,a);c?wp(d,c,b):xp(d,b)}
function zp(a,b,c){var d=new Fh;ud(d,78,Gh,a);c?wp(d,c,b):xp(d,b)}
function Ap(a,b,c){var d=new Fh;ud(d,208,Gh,a);c?wp(d,c,b):xp(d,b)}
function Bp(a,b,c){var d=new Fh;ud(d,156,Gh,a);c?wp(d,c,b):xp(d,b)}
function Cp(a,b,c){var d=new Fh;ud(d,215,Gh,a);c?wp(d,c,b):xp(d,b)}
function Dp(a,b,c){var d=new Fh;ud(d,111,Gh,a);c?wp(d,c,b):xp(d,b)}
;var Ep=new Set,Fp=0,Gp=0,Hp=0,Ip=[],Jp=["PhantomJS","Googlebot","TO STOP THIS SECURITY SCAN go/scan"];function dk(a){Kp(a)}
function Lp(a){Kp(a,"WARNING")}
function Kp(a,b,c,d,e,f){f=void 0===f?{}:f;f.name=c||L("INNERTUBE_CONTEXT_CLIENT_NAME",1);f.version=d||L("INNERTUBE_CONTEXT_CLIENT_VERSION");var g=f||{},h=void 0===b?"ERROR":b;h=void 0===h?"ERROR":h;if(a){a.hasOwnProperty("level")&&a.level&&(h=a.level);if(M("console_log_js_exceptions")){var k=[];k.push("Name: "+a.name);k.push("Message: "+a.message);a.hasOwnProperty("params")&&k.push("Error Params: "+JSON.stringify(a.params));a.hasOwnProperty("args")&&k.push("Error args: "+JSON.stringify(a.args));
k.push("File name: "+a.fileName);k.push("Stacktrace: "+a.stack);window.console.log(k.join("\n"),a)}if(!(5<=Fp)){var m=Ip,p=ye(a),u=p.message||"Unknown Error",x=p.name||"UnknownError",v=p.stack||a.j||"Not available";if(v.startsWith(x+": "+u)){var E=v.split("\n");E.shift();v=E.join("\n")}var G=p.lineNumber||"Not available",K=p.fileName||"Not available",N=v,O=0;if(a.hasOwnProperty("args")&&a.args&&a.args.length)for(var S=0;S<a.args.length&&!(O=sp(a.args[S],"params."+S,g,O),500<=O);S++);else if(a.hasOwnProperty("params")&&
a.params){var ka=a.params;if("object"===typeof a.params)for(var V in ka){if(ka[V]){var W="params."+V,Oa=up(ka[V]);g[W]=Oa;O+=W.length+Oa.length;if(500<O)break}}else g.params=up(ka)}if(m.length)for(var wa=0;wa<m.length&&!(O=sp(m[wa],"params.context."+wa,g,O),500<=O);wa++);navigator.vendor&&!g.hasOwnProperty("vendor")&&(g["device.vendor"]=navigator.vendor);var F={message:u,name:x,lineNumber:G,fileName:K,stack:N,params:g,sampleWeight:1},Da=Number(a.columnNumber);isNaN(Da)||(F.lineNumber=F.lineNumber+
":"+Da);if("IGNORED"===a.level)var va=0;else a:{for(var Qn=op(),Rn=q(Qn.ga),Bi=Rn.next();!Bi.done;Bi=Rn.next()){var Sn=Bi.value;if(F.message&&F.message.match(Sn.wp)){va=Sn.weight;break a}}for(var Tn=q(Qn.fa),Ci=Tn.next();!Ci.done;Ci=Tn.next()){var Un=Ci.value;if(Un.ka(F)){va=Un.weight;break a}}va=1}F.sampleWeight=va;for(var Vn=q(jp),Di=Vn.next();!Di.done;Di=Vn.next()){var Ei=Di.value;if(Ei.Ra[F.name])for(var Wn=q(Ei.Ra[F.name]),Fi=Wn.next();!Fi.done;Fi=Wn.next()){var Xn=Fi.value,Rf=F.message.match(Xn.regexp);
if(Rf){F.params["params.error.original"]=Rf[0];for(var Gi=Xn.groups,Yn={},Wc=0;Wc<Gi.length;Wc++)Yn[Gi[Wc]]=Rf[Wc+1],F.params["params.error."+Gi[Wc]]=Rf[Wc+1];F.message=Ei.hb(Yn);break}}}F.params||(F.params={});var Zn=op();F.params["params.errorServiceSignature"]="msg="+Zn.ga.length+"&cb="+Zn.fa.length;F.params["params.serviceWorker"]="false";y.document&&y.document.querySelectorAll&&(F.params["params.fscripts"]=String(document.querySelectorAll("script:not([nonce])").length));Bb("sample").constructor!==
zb&&(F.params["params.fconst"]="true");window.yterr&&"function"===typeof window.yterr&&window.yterr(F);if(0!==F.sampleWeight&&!Ep.has(F.message)){if("ERROR"===h){pp.ia("handleError",F);if(M("record_app_crashed_web")&&0===Hp&&1===F.sampleWeight)if(Hp++,M("errors_via_jspb")){var Hi=new gh;C(Hi,1,1);if(!M("report_client_error_with_app_crash_ks")){var $n=new bh;C($n,1,F.message);var ao=new ch;D(ao,3,$n);var bo=new dh;D(bo,5,ao);var co=new eh;D(co,9,bo);D(Hi,4,co)}var eo=new Fh;ud(eo,20,Gh,Hi);xp(eo)}else{var fo=
{appCrashType:"APP_CRASH_TYPE_BREAKPAD"};M("report_client_error_with_app_crash_ks")||(fo.systemHealth={crashData:{clientError:{logMessage:{message:F.message}}}});ek("appCrashed",fo)}Gp++}else"WARNING"===h&&pp.ia("handleWarning",F);if(M("kevlar_gel_error_routing"))a:{var Yd=h;if(M("errors_via_jspb")){if(Mp())var ho=void 0;else{var Xc=new Zg;C(Xc,1,F.stack);F.fileName&&C(Xc,4,F.fileName);var sb=F.lineNumber&&F.lineNumber.split?F.lineNumber.split(":"):[];0!==sb.length&&(1!==sb.length||isNaN(Number(sb[0]))?
2!==sb.length||isNaN(Number(sb[0]))||isNaN(Number(sb[1]))||(C(Xc,2,Number(sb[0])),C(Xc,3,Number(sb[1]))):C(Xc,2,Number(sb[0])));var mc=new bh;C(mc,1,F.message);C(mc,3,F.name);C(mc,6,F.sampleWeight);"ERROR"===Yd?C(mc,2,2):"WARNING"===Yd?C(mc,2,1):C(mc,2,0);var Ii=new $g;C(Ii,1,!0);ud(Ii,3,ah,Xc);var Mb=new Wg;C(Mb,3,window.location.href);for(var io=L("FEXP_EXPERIMENTS",[]),Ji=0;Ji<io.length;Ji++){var vt=io[Ji];cd(Mb);pd(Mb,5).push(vt)}var Ki=L("LATEST_ECATCHER_SERVICE_TRACKING_PARAMS");if(!Th()&&Ki)for(var jo=
q(Object.keys(Ki)),nc=jo.next();!nc.done;nc=jo.next()){var ko=nc.value,Li=new Yg;C(Li,1,ko);Li.setValue(String(Ki[ko]));vd(Mb,4,Yg,Li)}var Mi=F.params;if(Mi){var lo=q(Object.keys(Mi));for(nc=lo.next();!nc.done;nc=lo.next()){var mo=nc.value,Ni=new Yg;C(Ni,1,"client."+mo);Ni.setValue(String(Mi[mo]));vd(Mb,4,Yg,Ni)}}var no=L("SERVER_NAME"),oo=L("SERVER_VERSION");if(no&&oo){var Oi=new Yg;C(Oi,1,"server.name");Oi.setValue(no);vd(Mb,4,Yg,Oi);var Pi=new Yg;C(Pi,1,"server.version");Pi.setValue(oo);vd(Mb,
4,Yg,Pi)}var Sf=new ch;D(Sf,1,Mb);D(Sf,2,Ii);D(Sf,3,mc);ho=Sf}var po=ho;if(!po)break a;var qo=new Fh;ud(qo,163,Gh,po);xp(qo)}else{if(Mp())var ro=void 0;else{var Zd={stackTrace:F.stack};F.fileName&&(Zd.filename=F.fileName);var tb=F.lineNumber&&F.lineNumber.split?F.lineNumber.split(":"):[];0!==tb.length&&(1!==tb.length||isNaN(Number(tb[0]))?2!==tb.length||isNaN(Number(tb[0]))||isNaN(Number(tb[1]))||(Zd.lineNumber=Number(tb[0]),Zd.columnNumber=Number(tb[1])):Zd.lineNumber=Number(tb[0]));var Qi={level:"ERROR_LEVEL_UNKNOWN",
message:F.message,errorClassName:F.name,sampleWeight:F.sampleWeight};"ERROR"===Yd?Qi.level="ERROR_LEVEL_ERROR":"WARNING"===Yd&&(Qi.level="ERROR_LEVEL_WARNNING");var wt={isObfuscated:!0,browserStackInfo:Zd},Yc={pageUrl:window.location.href,kvPairs:[]};L("FEXP_EXPERIMENTS")&&(Yc.experimentIds=L("FEXP_EXPERIMENTS"));var Ri=L("LATEST_ECATCHER_SERVICE_TRACKING_PARAMS");if(!Th()&&Ri)for(var so=q(Object.keys(Ri)),oc=so.next();!oc.done;oc=so.next()){var to=oc.value;Yc.kvPairs.push({key:to,value:String(Ri[to])})}var Si=
F.params;if(Si){var uo=q(Object.keys(Si));for(oc=uo.next();!oc.done;oc=uo.next()){var vo=oc.value;Yc.kvPairs.push({key:"client."+vo,value:String(Si[vo])})}}var wo=L("SERVER_NAME"),xo=L("SERVER_VERSION");wo&&xo&&(Yc.kvPairs.push({key:"server.name",value:wo}),Yc.kvPairs.push({key:"server.version",value:xo}));ro={errorMetadata:Yc,stackTrace:wt,logMessage:Qi}}var yo=ro;if(!yo)break a;ek("clientError",yo)}if("ERROR"===Yd||M("errors_flush_gel_always_killswitch"))M("web_fp_via_jspb")&&ip(!0),ip()}if(!M("suppress_error_204_logging")){var $d=
F.params||{},Nb={urlParams:{a:"logerror",t:"jserror",type:F.name,msg:F.message.substr(0,250),line:F.lineNumber,level:h,"client.name":$d.name},postParams:{url:L("PAGE_NAME",window.location.href),file:F.fileName},method:"POST"};$d.version&&(Nb["client.version"]=$d.version);if(Nb.postParams){F.stack&&(Nb.postParams.stack=F.stack);for(var zo=q(Object.keys($d)),Ti=zo.next();!Ti.done;Ti=zo.next()){var Ao=Ti.value;Nb.postParams["client."+Ao]=$d[Ao]}var Ui=L("LATEST_ECATCHER_SERVICE_TRACKING_PARAMS");if(Ui)for(var Bo=
q(Object.keys(Ui)),Vi=Bo.next();!Vi.done;Vi=Bo.next()){var Co=Vi.value;Nb.postParams[Co]=Ui[Co]}var Do=L("SERVER_NAME"),Eo=L("SERVER_VERSION");Do&&Eo&&(Nb.postParams["server.name"]=Do,Nb.postParams["server.version"]=Eo)}Wi(L("ECATCHER_REPORT_HOST","")+"/error_204",Nb)}try{Ep.add(F.message)}catch(Vu){}Fp++}}}}
function Mp(){for(var a=q(Jp),b=a.next();!b.done;b=a.next())if(Vj(b.value.toLowerCase()))return!0;return!1}
function Np(a){var b=Ia.apply(1,arguments);a.args||(a.args=[]);a.args.push.apply(a.args,fa(b))}
;function Op(){this.register=new Map}
function Pp(a){a=q(a.register.values());for(var b=a.next();!b.done;b=a.next())b.value.zp("ABORTED")}
Op.prototype.clear=function(){Pp(this);this.register.clear()};
var Qp=new Op;var Rp=Date.now().toString();
function Sp(){a:{if(window.crypto&&window.crypto.getRandomValues)try{var a=Array(16),b=new Uint8Array(16);window.crypto.getRandomValues(b);for(var c=0;c<a.length;c++)a[c]=b[c];var d=a;break a}catch(e){}d=Array(16);for(a=0;16>a;a++){b=Date.now();for(c=0;c<b%23;c++)d[a]=Math.random();d[a]=Math.floor(256*Math.random())}if(Rp)for(a=1,b=0;b<Rp.length;b++)d[a%16]=d[a%16]^d[(a-1)%16]/4^Rp.charCodeAt(b),a++}a=[];for(b=0;b<d.length;b++)a.push("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789-_".charAt(d[b]&63));
return a.join("")}
;var Tp=y.ytLoggingDocDocumentNonce_;Tp||(Tp=Sp(),z("ytLoggingDocDocumentNonce_",Tp));var Up=Tp;var Vp={Jg:0,wd:1,Gd:2,yk:3,Lg:4,Jo:5,rl:6,Tm:7,rm:8,0:"DEFAULT",1:"CHAT",2:"CONVERSATIONS",3:"MINIPLAYER",4:"DIALOG",5:"VOZ",6:"MUSIC_WATCH_TABS",7:"SHARE",8:"PUSH_NOTIFICATIONS"};function Wp(a){this.i=a}
function Xp(a){return new Wp({trackingParams:a})}
Wp.prototype.getAsJson=function(){var a={};void 0!==this.i.trackingParams?a.trackingParams=this.i.trackingParams:(a.veType=this.i.veType,void 0!==this.i.veCounter&&(a.veCounter=this.i.veCounter),void 0!==this.i.elementIndex&&(a.elementIndex=this.i.elementIndex));void 0!==this.i.dataElement&&(a.dataElement=this.i.dataElement.getAsJson());void 0!==this.i.youtubeData&&(a.youtubeData=this.i.youtubeData);return a};
Wp.prototype.getAsJspb=function(){var a=new ih;void 0!==this.i.trackingParams?C(a,1,this.i.trackingParams):(void 0!==this.i.veType&&C(a,2,this.i.veType),void 0!==this.i.veCounter&&C(a,6,this.i.veCounter),void 0!==this.i.elementIndex&&C(a,3,this.i.elementIndex));if(void 0!==this.i.dataElement){var b=this.i.dataElement.getAsJspb();D(a,7,b)}void 0!==this.i.youtubeData&&D(a,8,this.i.jspbYoutubeData);return a};
Wp.prototype.toString=function(){return JSON.stringify(this.getAsJson())};
Wp.prototype.isClientVe=function(){return!this.i.trackingParams&&!!this.i.veType};function Yp(a){a=void 0===a?0:a;return 0===a?"client-screen-nonce":"client-screen-nonce."+a}
function Zp(a){a=void 0===a?0:a;return 0===a?"ROOT_VE_TYPE":"ROOT_VE_TYPE."+a}
function $p(a){return L(Zp(void 0===a?0:a))}
z("yt_logging_screen.getRootVeType",$p);function aq(a){return(a=$p(void 0===a?0:a))?new Wp({veType:a,youtubeData:void 0,jspbYoutubeData:void 0}):null}
function bq(){var a=L("csn-to-ctt-auth-info");a||(a={},Sh("csn-to-ctt-auth-info",a));return a}
function cq(a){a=L(Yp(void 0===a?0:a));if(!a&&!L("USE_CSN_FALLBACK",!0))return null;a||(a="UNDEFINED_CSN");return a?a:null}
z("yt_logging_screen.getCurrentCsn",cq);function dq(a,b,c){var d=bq();(c=cq(c))&&delete d[c];b&&(d[a]=b)}
function eq(a){return bq()[a]}
z("yt_logging_screen.getCttAuthInfo",eq);
function fq(a,b,c,d){c=void 0===c?0:c;if(a!==L(Yp(c))||b!==L(Zp(c)))dq(a,d,c),Sh(Yp(c),a),Sh(Zp(c),b),b=function(){setTimeout(function(){if(a)if(M("web_time_via_jspb")){var e=new jh;C(e,1,Up);C(e,2,a);M("use_default_heartbeat_client")?Dp(e):Dp(e,void 0,ln)}else e={clientDocumentNonce:Up,clientScreenNonce:a},M("use_default_heartbeat_client")?ek("foregroundHeartbeatScreenAssociated",e):gp("foregroundHeartbeatScreenAssociated",e,ln)},0)},"requestAnimationFrame"in window?window.requestAnimationFrame(b):
b()}
z("yt_logging_screen.setCurrentScreen",fq);var gq=window.yt&&window.yt.msgs_||window.ytcfg&&window.ytcfg.msgs||{};z("yt.msgs_",gq);function hq(a){Nh(gq,arguments)}
;var iq={vd:3611,Hc:27686,Ic:85013,Jc:23462,Lc:42016,Mc:62407,Nc:26926,Kc:43781,Oc:51236,Pc:79148,Qc:50160,Rc:77504,ed:87907,fd:18630,gd:54445,hd:80935,jd:152172,kd:105675,ld:150723,md:37521,nd:147285,od:47786,pd:98349,qd:123695,rd:6827,sd:29434,td:7282,ud:124448,yd:32276,xd:76278,zd:147868,Ad:147869,Bd:93911,Cd:106531,Dd:27259,Ed:27262,Fd:27263,Hd:21759,Id:27107,Jd:62936,Kd:49568,Ld:38408,Md:80637,Nd:68727,Od:68728,Pd:80353,Qd:80356,Rd:74610,Sd:45707,Td:83962,Ud:83970,Vd:46713,Wd:89711,Xd:74612,Yd:93265,
Zd:74611,ae:131380,ce:128979,de:139311,ee:128978,be:131391,ge:105350,ie:139312,je:134800,he:131392,le:113533,me:93252,ne:99357,pe:94521,qe:114252,re:113532,se:94522,oe:94583,te:88E3,ue:139580,we:93253,xe:93254,ye:94387,ze:94388,Ae:93255,Be:97424,ke:72502,Ce:110111,De:76019,Fe:117092,Ge:117093,Ee:89431,He:110466,Ie:77240,Je:60508,Ke:148123,Le:148124,Me:137401,Ne:137402,Oe:137046,Pe:73393,Qe:113534,Re:92098,Se:131381,Te:84517,Ue:83759,Ve:80357,We:86113,Xe:72598,Ye:72733,Ze:107349,af:124275,bf:118203,
cf:133275,df:152569,ef:133274,ff:133272,gf:133273,hf:133276,jf:144507,kf:143247,lf:143248,mf:143249,nf:143250,pf:143251,qf:144401,sf:117431,rf:133797,tf:128572,uf:133405,vf:117429,wf:117430,xf:117432,yf:120080,zf:117259,Af:121692,Bf:145656,Cf:145655,Df:145653,Ef:145654,Ff:145657,Gf:132972,Hf:133051,If:133658,Jf:132971,Kf:97615,Mf:143359,Lf:143356,Of:143361,Nf:143358,Qf:143360,Pf:143357,Rf:142303,Sf:143353,Tf:143354,Uf:144479,Vf:143355,Wf:31402,Yf:133624,Zf:146477,ag:133623,cg:133622,Xf:133621,dg:84774,
eg:95117,fg:150497,gg:98930,hg:98931,ig:98932,jg:43347,kg:129889,lg:149123,mg:45474,ng:100352,og:84758,pg:98443,qg:117985,rg:74613,sg:74614,tg:64502,ug:136032,vg:74615,wg:74616,xg:122224,yg:74617,zg:77820,Ag:74618,Bg:93278,Cg:93274,Dg:93275,Eg:93276,Fg:22110,Gg:29433,Hg:133798,Ig:132295,Kg:120541,Mg:82047,Ng:113550,Og:75836,Pg:75837,Qg:42352,Rg:84512,Sg:76065,Tg:75989,Yg:16623,Zg:32594,ah:27240,bh:32633,dh:74858,fh:3945,eh:16989,gh:45520,hh:25488,ih:25492,jh:25494,kh:55760,lh:14057,mh:18451,nh:57204,
oh:57203,ph:17897,qh:57205,rh:18198,sh:17898,th:17909,uh:43980,vh:46220,wh:11721,xh:147994,yh:49954,zh:96369,Ah:3854,Bh:151633,Ch:56251,Dh:25624,Eh:152036,Vh:16906,Wh:99999,Xh:68172,Yh:27068,Zh:47973,ai:72773,bi:26970,ci:26971,di:96805,fi:17752,gi:73233,hi:109512,ii:22256,ji:14115,ki:22696,li:89278,mi:89277,ni:109513,oi:43278,ri:43459,si:43464,ti:89279,vi:43717,wi:55764,xi:22255,yi:147912,zi:89281,Ai:40963,Bi:43277,Ci:43442,Di:91824,Ei:120137,Fi:96367,Gi:36850,Hi:72694,Ii:37414,Ji:36851,Li:124863,
Ki:121343,Mi:73491,Ni:54473,Oi:43375,Pi:46674,Qi:143815,Ri:139095,Si:144402,Ti:149968,Ui:149969,Vi:32473,Wi:72901,Xi:72906,Yi:50947,Zi:50612,aj:50613,bj:50942,cj:84938,dj:84943,ej:84939,fj:84941,gj:84944,hj:84940,ij:84942,jj:35585,kj:51926,lj:79983,mj:63238,nj:18921,oj:63241,pj:57893,qj:41182,rj:135732,sj:33424,tj:22207,uj:42993,vj:36229,wj:22206,xj:22205,yj:18993,zj:19001,Aj:18990,Bj:18991,Cj:18997,Dj:18725,Ej:19003,Fj:36874,Gj:44763,Hj:33427,Ij:67793,Jj:22182,Kj:37091,Lj:34650,Mj:50617,Nj:47261,
Oj:22287,Pj:25144,Qj:97917,Rj:62397,Sj:150871,Tj:150874,Uj:125598,Vj:137935,Wj:36961,Xj:108035,Yj:27426,Zj:27857,ak:27846,bk:27854,ck:69692,dk:61411,ek:39299,fk:38696,gk:62520,hk:36382,ik:108701,jk:50663,kk:36387,lk:14908,mk:37533,nk:105443,pk:61635,qk:62274,rk:133818,sk:65702,tk:65703,uk:65701,vk:76256,wk:37671,xk:49953,zk:36216,Ak:28237,Bk:39553,Ck:29222,Dk:26107,Ek:38050,Fk:26108,Hk:120745,Gk:26109,Ik:26110,Jk:66881,Kk:28236,Lk:14586,Mk:57929,Nk:74723,Ok:44098,Pk:44099,Sk:23528,Tk:61699,Qk:134104,
Rk:134103,Uk:59149,Vk:101951,Wk:97346,Xk:118051,Yk:95102,Zk:64882,al:119505,bl:63595,dl:63349,fl:95101,il:75240,jl:27039,kl:68823,ll:21537,ml:83464,nl:75707,ol:83113,pl:101952,ql:101953,sl:79610,ul:125755,vl:24402,wl:24400,xl:32925,yl:57173,zl:122502,Al:145268,Bl:138480,Cl:64423,Dl:64424,El:33986,Fl:100828,Gl:129089,Hl:21409,Ll:135155,Ml:135156,Nl:135157,Ol:135158,Pl:135159,Ql:135160,Rl:135161,Sl:135162,Tl:135163,Ul:135164,Vl:135165,Wl:135166,Il:11070,Jl:11074,Kl:17880,Xl:14001,Zl:30709,am:30707,
bm:30711,cm:30710,dm:30708,Yl:26984,em:146143,fm:63648,gm:63649,hm:51879,im:111059,jm:5754,km:20445,lm:151152,nm:130975,mm:130976,om:110386,pm:113746,qm:66557,sm:17310,tm:28631,um:21589,vm:68012,wm:60480,xm:138664,ym:141121,zm:31571,Am:141978,Bm:150105,Cm:150106,Dm:150107,Em:150108,Fm:76980,Gm:41577,Hm:45469,Im:38669,Jm:13768,Km:13777,Lm:141842,Mm:62985,Nm:4724,Om:59369,Pm:43927,Qm:43928,Rm:12924,Sm:100355,Vm:56219,Wm:27669,Xm:10337,Um:47896,Ym:122629,an:139723,Zm:139722,bn:121258,cn:107598,dn:127991,
en:96639,fn:107536,gn:130169,hn:96661,jn:145188,kn:96658,ln:116646,mn:121122,nn:96660,pn:127738,qn:127083,rn:147842,sn:104443,tn:96659,un:147595,vn:106442,wn:134840,xn:63667,yn:63668,zn:63669,An:130686,Bn:147036,Cn:78314,Dn:147799,En:148649,Fn:55761,Gn:127098,Hn:134841,In:96368,Jn:67374,Kn:48992,Ln:146176,Mn:49956,Nn:31961,On:26388,Pn:23811,Qn:5E4,Rn:126250,Sn:96370,Tn:47355,Un:47356,Vn:37935,Wn:45521,Xn:21760,Yn:83769,Zn:49977,ao:49974,bo:93497,co:93498,eo:34325,fo:140759,ho:115803,jo:123707,ko:100081,
lo:35309,mo:68314,no:25602,oo:100339,po:143516,qo:59018,ro:18248,so:50625,to:9729,uo:37168,vo:37169,wo:21667,xo:16749,yo:18635,zo:39305,Ao:18046,Bo:53969,Co:8213,Do:93926,Eo:102852,Fo:110099,Go:22678,Ho:69076,Io:137575,Ko:139224,Lo:100856,Mo:17736,No:3832,Oo:147111,Po:55759,Qo:64031,Wo:93044,Xo:93045,Yo:34388,Zo:17657,ap:17655,bp:39579,cp:39578,ep:77448,fp:8196,gp:11357,hp:69877,ip:8197,jp:82039};function jq(){var a=rb(kq),b;return hg(new ag(function(c,d){a.onSuccess=function(e){ti(e)?c(new lq(e)):d(new mq("Request failed, status="+(e&&"status"in e?e.status:-1),"net.badstatus",e))};
a.onError=function(e){d(new mq("Unknown request error","net.unknown",e))};
a.onTimeout=function(e){d(new mq("Request timed out","net.timeout",e))};
b=Wi("//googleads.g.doubleclick.net/pagead/id",a)}),function(c){c instanceof ig&&b.abort();
return fg(c)})}
function mq(a,b,c){Za.call(this,a+", errorCode="+b);this.errorCode=b;this.xhr=c;this.name="PromiseAjaxError"}
r(mq,Za);function lq(a){this.xhr=a}
;function nq(){this.i=0;this.da=null}
nq.prototype.then=function(a,b,c){return 1===this.i&&a?(a=a.call(c,this.da))&&"function"===typeof a.then?a:oq(a):2===this.i&&b?(a=b.call(c,this.da))&&"function"===typeof a.then?a:pq(a):this};
nq.prototype.getValue=function(){return this.da};
nq.prototype.$goog_Thenable=!0;function pq(a){var b=new nq;a=void 0===a?null:a;b.i=2;b.da=void 0===a?null:a;return b}
function oq(a){var b=new nq;a=void 0===a?null:a;b.i=1;b.da=void 0===a?null:a;return b}
;function qq(a,b){return{method:void 0===b?"POST":b,mode:oi(a)?"same-origin":"cors",credentials:oi(a)?"same-origin":"include"}}
;function rq(){if(re()||Uj&&Vj("applewebkit")&&!Vj("version")&&(!Vj("safari")||Vj("gsa/"))||wc&&Vj("version/"))return!0;if(M("enable_web_eom_visitor_data"))return L("EOM_VISITOR_DATA")?!1:!0;var a=L("INNERTUBE_CLIENT_NAME");return!a||"WEB"!==a&&"MWEB"!==a?!0:(a=gj("CONSENT"))?a.startsWith("YES+"):!0}
;function sq(a){a:{var b=a.raw_embedded_player_response;if(!b&&(a=a.embedded_player_response))try{b=JSON.parse(a)}catch(d){b="EMBEDDED_PLAYER_MODE_UNKNOWN";break a}if(b)b:{for(var c in hf)if(hf[c]==b.embeddedPlayerMode){b=hf[c];break b}b="EMBEDDED_PLAYER_MODE_UNKNOWN"}else b="EMBEDDED_PLAYER_MODE_UNKNOWN"}return"EMBEDDED_PLAYER_MODE_PFL"===b}
;function tq(a){Za.call(this,a.message||a.description||a.name);this.isMissing=a instanceof uq;this.isTimeout=a instanceof mq&&"net.timeout"==a.errorCode;this.isCanceled=a instanceof ig}
r(tq,Za);tq.prototype.name="BiscottiError";function uq(){Za.call(this,"Biscotti ID is missing from server")}
r(uq,Za);uq.prototype.name="BiscottiMissingError";var kq={format:"RAW",method:"GET",timeout:5E3,withCredentials:!0},vq=null;
function di(){if(M("disable_biscotti_fetch_entirely_for_all_web_clients"))return fg(Error("Biscotti id fetching has been disabled entirely."));if(!rq())return fg(Error("User has not consented - not fetching biscotti id."));var a=L("PLAYER_VARS",{});if("1"==pb(a))return fg(Error("Biscotti ID is not available in private embed mode"));if(M("embeds_web_disable_ads_for_pfl")&&sq(a))return fg(Error("Biscotti id fetching has been disabled for pfl."));vq||(vq=hg(jq().then(wq),function(b){return xq(2,b)}));
return vq}
function wq(a){a=a.xhr.responseText;if(0!=a.lastIndexOf(")]}'",0))throw new uq;a=JSON.parse(a.substr(4));if(1<(a.type||1))throw new uq;a=a.id;ei(a);vq=oq(a);yq(18E5,2);return a}
function xq(a,b){b=new tq(b);ei("");vq=pq(b);0<a&&yq(12E4,a-1);throw b;}
function yq(a,b){ui(function(){hg(jq().then(wq,function(c){return xq(b,c)}),ab)},a)}
function zq(){try{var a=A("yt.ads.biscotti.getId_");return a?a():di()}catch(b){return fg(b)}}
;function Aq(a){if("1"!=pb(L("PLAYER_VARS",{}))){a&&ci();try{zq().then(function(){},function(){}),ui(Aq,18E5)}catch(b){ai(b)}}}
;function Bq(){this.Cc=!0}
function Cq(a){var b={},c=te([]);c&&(b.Authorization=c,c=a=null==a?void 0:a.sessionIndex,void 0===c&&(c=Number(L("SESSION_INDEX",0)),c=isNaN(c)?0:c),M("voice_search_auth_header_removal")||(b["X-Goog-AuthUser"]=c),"INNERTUBE_HOST_OVERRIDE"in Rh||(b["X-Origin"]=window.location.origin),void 0===a&&"DELEGATED_SESSION_ID"in Rh&&(b["X-Goog-PageId"]=L("DELEGATED_SESSION_ID")));return b}
;var Dq=Symbol("injectionDeps");function Eq(a){this.name=a}
Eq.prototype.toString=function(){return"InjectionToken("+this.name+")"};
function Fq(){this.key=Gq}
function Hq(){this.providers=new Map;this.i=new Map}
Hq.prototype.resolve=function(a){return a instanceof Fq?Iq(this,a.key,[],!0):Iq(this,a,[])};
function Iq(a,b,c,d){d=void 0===d?!1:d;if(-1<c.indexOf(b))throw Error("Deps cycle for: "+b);if(a.i.has(b))return a.i.get(b);if(!a.providers.has(b)){if(d)return;throw Error("No provider for: "+b);}d=a.providers.get(b);c.push(b);if(d.Gc)var e=d.Gc;else if(d.Fc)e=d[Dq]?Jq(a,d[Dq],c):[],e=d.Fc.apply(d,fa(e));else if(d.Nb){e=d.Nb;var f=e[Dq]?Jq(a,e[Dq],c):[];e=new (Function.prototype.bind.apply(e,[null].concat(fa(f))))}else throw Error("Could not resolve providers for: "+b);c.pop();d.Ep||a.i.set(b,e);
return e}
function Jq(a,b,c){return b?b.map(function(d){return d instanceof Fq?Iq(a,d.key,c,!0):Iq(a,d,c)}):[]}
;var Kq;var Lq={identityType:"UNAUTHENTICATED_IDENTITY_TYPE_UNKNOWN"};var Mq=new Map([["dark","USER_INTERFACE_THEME_DARK"],["light","USER_INTERFACE_THEME_LIGHT"]]);function Nq(){var a=void 0===a?window.location.href:a;if(M("kevlar_disable_theme_param"))return null;$b(ac(5,a));try{var b=mi(a).theme;return Mq.get(b)||null}catch(c){}return null}
;function Oq(){this.i={};if(this.j=hj()){var a=gj("CONSISTENCY");a&&Pq(this,{encryptedTokenJarContents:a})}}
Oq.prototype.handleResponse=function(a,b){var c,d;b=(null==(c=b.Z.context)?void 0:null==(d=c.request)?void 0:d.consistencyTokenJars)||[];var e;if(a=null==(e=a.responseContext)?void 0:e.consistencyTokenJar){e=q(b);for(c=e.next();!c.done;c=e.next())delete this.i[c.value.encryptedTokenJarContents];Pq(this,a)}};
function Pq(a,b){if(b.encryptedTokenJarContents&&(a.i[b.encryptedTokenJarContents]=b,"string"===typeof b.expirationSeconds)){var c=Number(b.expirationSeconds);setTimeout(function(){delete a.i[b.encryptedTokenJarContents]},1E3*c);
a.j&&fj("CONSISTENCY",b.encryptedTokenJarContents,c,void 0,!0)}}
;var Qq=window.location.hostname.split(".").slice(-2).join(".");function Rq(){var a=L("LOCATION_PLAYABILITY_TOKEN");"TVHTML5"===L("INNERTUBE_CLIENT_NAME")&&(this.i=Sq(this))&&(a=this.i.get("yt-location-playability-token"));a&&(this.locationPlayabilityToken=a,this.j=void 0)}
var Tq;Rq.getInstance=function(){Tq=A("yt.clientLocationService.instance");Tq||(Tq=new Rq,z("yt.clientLocationService.instance",Tq));return Tq};
Rq.prototype.setLocationOnInnerTubeContext=function(a){a.client||(a.client={});this.j?(a.client.locationInfo||(a.client.locationInfo={}),a.client.locationInfo.latitudeE7=Math.floor(1E7*this.j.coords.latitude),a.client.locationInfo.longitudeE7=Math.floor(1E7*this.j.coords.longitude),a.client.locationInfo.horizontalAccuracyMeters=Math.round(this.j.coords.accuracy),a.client.locationInfo.forceLocationPlayabilityTokenRefresh=!0):this.locationPlayabilityToken&&(a.client.locationPlayabilityToken=this.locationPlayabilityToken)};
Rq.prototype.handleResponse=function(a){var b;a=null==(b=a.responseContext)?void 0:b.locationPlayabilityToken;void 0!==a&&(this.locationPlayabilityToken=a,this.j=void 0,"TVHTML5"===L("INNERTUBE_CLIENT_NAME")?(this.i=Sq(this))&&this.i.set("yt-location-playability-token",a,15552E3):fj("YT_CL",JSON.stringify({loctok:a}),15552E3,Qq,!0))};
function Sq(a){return void 0===a.i?new Fj("yt-client-location"):a.i}
Rq.prototype.getCurrentPositionFromGeolocation=function(){var a=this;if(!(navigator&&navigator.geolocation&&navigator.geolocation.getCurrentPosition)||!M("web_enable_browser_geolocation_api")&&!M("enable_handoff_location_2fa_on_mweb"))return Promise.reject(Error("Geolocation unsupported"));var b=!1,c=1E4;M("enable_handoff_location_2fa_on_mweb")&&(b=!0,c=15E3);return new Promise(function(d,e){navigator.geolocation.getCurrentPosition(function(f){a.j=f;d(f)},function(f){e(f)},{enableHighAccuracy:b,
maximumAge:0,timeout:c})})};
Rq.prototype.createUnpluggedLocationInfo=function(a){var b={};a=a.coords;if(null==a?0:a.latitude)b.latitudeE7=Math.floor(1E7*a.latitude);if(null==a?0:a.longitude)b.longitudeE7=Math.floor(1E7*a.longitude);if(null==a?0:a.accuracy)b.locationRadiusMeters=Math.round(a.accuracy);return b};function Uq(a,b){var c;if((null==(c=a.signalServiceEndpoint)?0:c.signal)&&b.Aa&&(c=b.Aa[a.signalServiceEndpoint.signal]))return c();var d;if((null==(d=a.continuationCommand)?0:d.request)&&b.Ub&&(d=b.Ub[a.continuationCommand.request]))return d();for(var e in a)if(b.rb[e]&&(a=b.rb[e]))return a()}
;function Vq(a){return function(){return new a}}
;var Wq={},Xq=(Wq.WEB_UNPLUGGED="^unplugged/",Wq.WEB_UNPLUGGED_ONBOARDING="^unplugged/",Wq.WEB_UNPLUGGED_OPS="^unplugged/",Wq.WEB_UNPLUGGED_PUBLIC="^unplugged/",Wq.WEB_CREATOR="^creator/",Wq.WEB_KIDS="^kids/",Wq.WEB_EXPERIMENTS="^experiments/",Wq.WEB_MUSIC="^music/",Wq.WEB_REMIX="^music/",Wq.WEB_MUSIC_EMBEDDED_PLAYER="^music/",Wq.WEB_MUSIC_EMBEDDED_PLAYER="^main_app/|^sfv/",Wq);
function Yq(a){var b=void 0===b?"UNKNOWN_INTERFACE":b;if(1===a.length)return a[0];var c=Xq[b];if(c){var d=new RegExp(c),e=q(a);for(c=e.next();!c.done;c=e.next())if(c=c.value,d.exec(c))return c}var f=[];Object.entries(Xq).forEach(function(g){var h=q(g);g=h.next().value;h=h.next().value;b!==g&&f.push(h)});
d=new RegExp(f.join("|"));a.sort(function(g,h){return g.length-h.length});
e=q(a);for(c=e.next();!c.done;c=e.next())if(c=c.value,!d.exec(c))return c;return a[0]}
;function Zq(){}
Zq.prototype.s=function(a,b,c){b=void 0===b?{}:b;c=void 0===c?Lq:c;var d=a.clickTrackingParams,e=this.m,f=!1;f=void 0===f?!1:f;e=void 0===e?!1:e;var g=L("INNERTUBE_CONTEXT");if(g){g=ub(g);M("web_no_tracking_params_in_shell_killswitch")||delete g.clickTracking;g.client||(g.client={});var h=g.client;"MWEB"===h.clientName&&(h.clientFormFactor=L("IS_TABLET")?"LARGE_FORM_FACTOR":"SMALL_FORM_FACTOR");h.screenWidthPoints=window.innerWidth;h.screenHeightPoints=window.innerHeight;h.screenPixelDensity=Math.round(window.devicePixelRatio||
1);h.screenDensityFloat=window.devicePixelRatio||1;h.utcOffsetMinutes=-Math.floor((new Date).getTimezoneOffset());var k=void 0===k?!1:k;jj.getInstance();var m="USER_INTERFACE_THEME_LIGHT";mj(165)?m="USER_INTERFACE_THEME_DARK":mj(174)?m="USER_INTERFACE_THEME_LIGHT":!M("kevlar_legacy_browsers")&&window.matchMedia&&window.matchMedia("(prefers-color-scheme)").matches&&window.matchMedia("(prefers-color-scheme: dark)").matches&&(m="USER_INTERFACE_THEME_DARK");k=k?m:Nq()||m;h.userInterfaceTheme=k;if(!f){if(k=
tj())h.connectionType=k;M("web_log_effective_connection_type")&&(k=uj())&&(g.client.effectiveConnectionType=k)}var p;if(M("web_log_memory_total_kbytes")&&(null==(p=y.navigator)?0:p.deviceMemory)){var u;p=null==(u=y.navigator)?void 0:u.deviceMemory;g.client.memoryTotalKbytes=""+1E6*p}u=mi(y.location.href);!M("web_populate_internal_geo_killswitch")&&u.internalcountrycode&&(h.internalGeo=u.internalcountrycode);"MWEB"===h.clientName||"WEB"===h.clientName?(h.mainAppWebInfo={graftUrl:y.location.href},M("kevlar_woffle")&&
dj.i&&(h.mainAppWebInfo.pwaInstallabilityStatus=dj.i.i?"PWA_INSTALLABILITY_STATUS_CAN_BE_INSTALLED":"PWA_INSTALLABILITY_STATUS_UNKNOWN"),h.mainAppWebInfo.webDisplayMode=ej(),h.mainAppWebInfo.isWebNativeShareAvailable=navigator&&void 0!==navigator.share):"TVHTML5"===h.clientName&&(!M("web_lr_app_quality_killswitch")&&(u=L("LIVING_ROOM_APP_QUALITY"))&&(h.tvAppInfo=Object.assign(h.tvAppInfo||{},{appQuality:u})),u=L("LIVING_ROOM_CERTIFICATION_SCOPE"))&&(h.tvAppInfo=Object.assign(h.tvAppInfo||{},{certificationScope:u}));
if(!M("web_populate_time_zone_itc_killswitch")){b:{if("undefined"!==typeof Intl)try{var x=(new Intl.DateTimeFormat).resolvedOptions().timeZone;break b}catch(Oa){}x=void 0}x&&(h.timeZone=x)}(x=Wh())?h.experimentsToken=x:delete h.experimentsToken;x=Xh();Oq.i||(Oq.i=new Oq);h=Oq.i.i;u=[];p=0;for(var v in h)u[p++]=h[v];g.request=Object.assign({},g.request,{internalExperimentFlags:x,consistencyTokenJars:u});!M("web_prequest_context_killswitch")&&(v=L("INNERTUBE_CONTEXT_PREQUEST_CONTEXT"))&&(g.request.externalPrequestContext=
v);x=jj.getInstance();v=mj(58);x=x.get("gsml","");g.user=Object.assign({},g.user);v&&(g.user.enableSafetyMode=v);x&&(g.user.lockedSafetyMode=!0);M("warm_op_csn_cleanup")?e&&(f=cq())&&(g.clientScreenNonce=f):!f&&(f=cq())&&(g.clientScreenNonce=f);d&&(g.clickTracking={clickTrackingParams:d});if(d=A("yt.mdx.remote.remoteClient_"))g.remoteClient=d;M("web_enable_client_location_service")&&Rq.getInstance().setLocationOnInnerTubeContext(g);try{var E=pi(),G=E.bid;delete E.bid;g.adSignalsInfo={params:[],bid:G};
var K=q(Object.entries(E));for(var N=K.next();!N.done;N=K.next()){var O=q(N.value),S=O.next().value,ka=O.next().value;E=S;G=ka;d=void 0;null==(d=g.adSignalsInfo.params)||d.push({key:E,value:""+G})}}catch(Oa){Kp(Oa)}K=g}else Kp(Error("Error: No InnerTubeContext shell provided in ytconfig.")),K={};K={context:K};if(N=this.i(a)){this.j(K,N,b);var V;b="/youtubei/v1/"+Yq(this.l());var W;(a=null==(V=a.commandMetadata)?void 0:null==(W=V.webCommandMetadata)?void 0:W.apiUrl)&&(b=a);V=b;(W=L("INNERTUBE_HOST_OVERRIDE"))&&
(V=String(W)+String(cc(V)));W={};W.key=L("INNERTUBE_API_KEY");M("json_condensed_response")&&(W.prettyPrint="false");V=ni(V,W||{},!1);V={input:V,ra:qq(V),Z:K,config:Object.assign({},void 0)};V.config.Ha?V.config.Ha.identity=c:V.config.Ha={identity:c};return V}Kp(new hk("Error: Failed to create Request from Command.",a))};
da.Object.defineProperties(Zq.prototype,{m:{configurable:!0,enumerable:!0,get:function(){return!1}}});function $q(){}
r($q,Zq);$q.prototype.s=function(){return{input:"/getDatasyncIdsEndpoint",ra:qq("/getDatasyncIdsEndpoint","GET"),Z:{}}};
$q.prototype.l=function(){return[]};
$q.prototype.i=function(){};
$q.prototype.j=function(){};var ar={},br=(ar.GET_DATASYNC_IDS=Vq($q),ar);function cr(a){var b=Ia.apply(1,arguments);if(!dr(a)||b.some(function(d){return!dr(d)}))throw Error("Only objects may be merged.");
b=q(b);for(var c=b.next();!c.done;c=b.next())er(a,c.value);return a}
function er(a,b){for(var c in b)if(dr(b[c])){if(c in a&&!dr(a[c]))throw Error("Cannot merge an object into a non-object.");c in a||(a[c]={});er(a[c],b[c])}else if(fr(b[c])){if(c in a&&!fr(a[c]))throw Error("Cannot merge an array into a non-array.");c in a||(a[c]=[]);gr(a[c],b[c])}else a[c]=b[c];return a}
function gr(a,b){b=q(b);for(var c=b.next();!c.done;c=b.next())c=c.value,dr(c)?a.push(er({},c)):fr(c)?a.push(gr([],c)):a.push(c);return a}
function dr(a){return"object"===typeof a&&!Array.isArray(a)}
function fr(a){return"object"===typeof a&&Array.isArray(a)}
;function hr(a,b){Nl.call(this,1,arguments);this.timer=b}
r(hr,Nl);var ir=new Ol("aft-recorded",hr);var jr=window;function kr(){this.timing={};this.clearResourceTimings=function(){};
this.webkitClearResourceTimings=function(){};
this.mozClearResourceTimings=function(){};
this.msClearResourceTimings=function(){};
this.oClearResourceTimings=function(){}}
var Q=jr.performance||jr.mozPerformance||jr.msPerformance||jr.webkitPerformance||new kr;var lr=!1,mr={'script[name="scheduler/scheduler"]':"sj",'script[name="player/base"]':"pj",'link[rel="stylesheet"][name="www-player"]':"pc",'link[rel="stylesheet"][name="player/www-player"]':"pc",'script[name="desktop_polymer/desktop_polymer"]':"dpj",'link[rel="import"][name="desktop_polymer"]':"dph",'script[name="mobile-c3"]':"mcj",'link[rel="stylesheet"][name="mobile-c3"]':"mcc",'script[name="player-plasma-ias-phone/base"]':"mcppj",'script[name="player-plasma-ias-tablet/base"]':"mcptj",'link[rel="stylesheet"][name="mobile-polymer-player-ias"]':"mcpc",
'link[rel="stylesheet"][name="mobile-polymer-player-svg-ias"]':"mcpsc",'script[name="mobile_blazer_core_mod"]':"mbcj",'link[rel="stylesheet"][name="mobile_blazer_css"]':"mbc",'script[name="mobile_blazer_logged_in_users_mod"]':"mbliuj",'script[name="mobile_blazer_logged_out_users_mod"]':"mblouj",'script[name="mobile_blazer_noncore_mod"]':"mbnj","#player_css":"mbpc",'script[name="mobile_blazer_desktopplayer_mod"]':"mbpj",'link[rel="stylesheet"][name="mobile_blazer_tablet_css"]':"mbtc",'script[name="mobile_blazer_watch_mod"]':"mbwj"};
Va(Q.clearResourceTimings||Q.webkitClearResourceTimings||Q.mozClearResourceTimings||Q.msClearResourceTimings||Q.oClearResourceTimings||ab,Q);function nr(a){var b=or(a);if(b.aft)return b.aft;a=L((a||"")+"TIMING_AFT_KEYS",["ol"]);for(var c=a.length,d=0;d<c;d++){var e=b[a[d]];if(e)return e}return NaN}
function pr(){var a;if(M("csi_use_performance_navigation_timing")){var b,c,d,e=null==Q?void 0:null==(a=Q.getEntriesByType)?void 0:null==(b=a.call(Q,"navigation"))?void 0:null==(c=b[0])?void 0:null==(d=c.toJSON)?void 0:d.call(c);e?(e.requestStart=qr(e.requestStart),e.responseEnd=qr(e.responseEnd),e.redirectStart=qr(e.redirectStart),e.redirectEnd=qr(e.redirectEnd),e.domainLookupEnd=qr(e.domainLookupEnd),e.connectStart=qr(e.connectStart),e.connectEnd=qr(e.connectEnd),e.responseStart=qr(e.responseStart),
e.secureConnectionStart=qr(e.secureConnectionStart),e.domainLookupStart=qr(e.domainLookupStart),e.isPerformanceNavigationTiming=!0,a=e):a=Q.timing}else a=Q.timing;return a}
function rr(){return M("csi_use_time_origin")&&Q.timeOrigin?Math.floor(Q.timeOrigin):Q.timing.navigationStart}
function qr(a){return Math.round(rr()+a)}
function sr(a){var b;(b=A("ytcsi."+(a||"")+"data_"))||(b={tick:{},info:{}},z("ytcsi."+(a||"")+"data_",b));return b}
function tr(a){a=sr(a);a.info||(a.info={});return a.info}
function or(a){a=sr(a);a.tick||(a.tick={});return a.tick}
function ur(a){a=sr(a);if(a.gel){var b=a.gel;b.gelInfos||(b.gelInfos={});b.gelTicks||(b.gelTicks={})}else a.gel={gelTicks:{},gelInfos:{}};return a.gel}
function vr(a){a=ur(a);a.gelInfos||(a.gelInfos={});return a.gelInfos}
function wr(a){var b=sr(a).nonce;b||(b=Sp(),sr(a).nonce=b);return b}
function xr(a){var b=or(a||""),c=nr(a);c&&!lr&&(Tl(ir,new hr(Math.round(c-b._start),a)),lr=!0)}
function yr(a,b){for(var c=q(Object.keys(b)),d=c.next();!d.done;d=c.next())if(d=d.value,!Object.keys(a).includes(d)||"object"===typeof b[d]&&!yr(a[d],b[d]))return!1;return!0}
;function zr(){if(Q.getEntriesByType){var a=Q.getEntriesByType("paint");if(a=hb(a,function(b){return"first-paint"===b.name}))return qr(a.startTime)}a=Q.timing;
return a.hc?Math.max(0,a.hc):0}
;function Ar(){var a=A("ytcsi.debug");a||(a=[],z("ytcsi.debug",a),z("ytcsi.reference",{}));return a}
function Br(a){a=a||"";var b=A("ytcsi.reference");b||(Ar(),b=A("ytcsi.reference"));if(b[a])return b[a];var c=Ar(),d={timerName:a,info:{},tick:{},span:{},jspbInfo:[]};c.push(d);return b[a]=d}
;var R={},Cr=(R.auto_search="LATENCY_ACTION_AUTO_SEARCH",R.ad_to_ad="LATENCY_ACTION_AD_TO_AD",R.ad_to_video="LATENCY_ACTION_AD_TO_VIDEO",R["analytics.explore"]="LATENCY_ACTION_CREATOR_ANALYTICS_EXPLORE",R.app_startup="LATENCY_ACTION_APP_STARTUP",R["artist.analytics"]="LATENCY_ACTION_CREATOR_ARTIST_ANALYTICS",R["artist.events"]="LATENCY_ACTION_CREATOR_ARTIST_CONCERTS",R["artist.presskit"]="LATENCY_ACTION_CREATOR_ARTIST_PROFILE",R.browse="LATENCY_ACTION_BROWSE",R.cast_splash="LATENCY_ACTION_CAST_SPLASH",
R.channels="LATENCY_ACTION_CHANNELS",R.creator_channel_dashboard="LATENCY_ACTION_CREATOR_CHANNEL_DASHBOARD",R["channel.analytics"]="LATENCY_ACTION_CREATOR_CHANNEL_ANALYTICS",R["channel.comments"]="LATENCY_ACTION_CREATOR_CHANNEL_COMMENTS",R["channel.content"]="LATENCY_ACTION_CREATOR_POST_LIST",R["channel.copyright"]="LATENCY_ACTION_CREATOR_CHANNEL_COPYRIGHT",R["channel.editing"]="LATENCY_ACTION_CREATOR_CHANNEL_EDITING",R["channel.monetization"]="LATENCY_ACTION_CREATOR_CHANNEL_MONETIZATION",R["channel.music"]=
"LATENCY_ACTION_CREATOR_CHANNEL_MUSIC",R["channel.playlists"]="LATENCY_ACTION_CREATOR_CHANNEL_PLAYLISTS",R["channel.translations"]="LATENCY_ACTION_CREATOR_CHANNEL_TRANSLATIONS",R["channel.videos"]="LATENCY_ACTION_CREATOR_CHANNEL_VIDEOS",R["channel.live_streaming"]="LATENCY_ACTION_CREATOR_LIVE_STREAMING",R.chips="LATENCY_ACTION_CHIPS",R["dialog.copyright_strikes"]="LATENCY_ACTION_CREATOR_DIALOG_COPYRIGHT_STRIKES",R["dialog.uploads"]="LATENCY_ACTION_CREATOR_DIALOG_UPLOADS",R.direct_playback="LATENCY_ACTION_DIRECT_PLAYBACK",
R.embed="LATENCY_ACTION_EMBED",R.entity_key_serialization_perf="LATENCY_ACTION_ENTITY_KEY_SERIALIZATION_PERF",R.entity_key_deserialization_perf="LATENCY_ACTION_ENTITY_KEY_DESERIALIZATION_PERF",R.explore="LATENCY_ACTION_EXPLORE",R.home="LATENCY_ACTION_HOME",R.library="LATENCY_ACTION_LIBRARY",R.live="LATENCY_ACTION_LIVE",R.live_pagination="LATENCY_ACTION_LIVE_PAGINATION",R.onboarding="LATENCY_ACTION_ONBOARDING",R.parent_profile_settings="LATENCY_ACTION_KIDS_PARENT_PROFILE_SETTINGS",R.parent_tools_collection=
"LATENCY_ACTION_PARENT_TOOLS_COLLECTION",R.parent_tools_dashboard="LATENCY_ACTION_PARENT_TOOLS_DASHBOARD",R.player_att="LATENCY_ACTION_PLAYER_ATTESTATION",R["post.comments"]="LATENCY_ACTION_CREATOR_POST_COMMENTS",R["post.edit"]="LATENCY_ACTION_CREATOR_POST_EDIT",R.prebuffer="LATENCY_ACTION_PREBUFFER",R.prefetch="LATENCY_ACTION_PREFETCH",R.profile_settings="LATENCY_ACTION_KIDS_PROFILE_SETTINGS",R.profile_switcher="LATENCY_ACTION_LOGIN",R.reel_watch="LATENCY_ACTION_REEL_WATCH",R.results="LATENCY_ACTION_RESULTS",
R.search_ui="LATENCY_ACTION_SEARCH_UI",R.search_suggest="LATENCY_ACTION_SUGGEST",R.search_zero_state="LATENCY_ACTION_SEARCH_ZERO_STATE",R.secret_code="LATENCY_ACTION_KIDS_SECRET_CODE",R.seek="LATENCY_ACTION_PLAYER_SEEK",R.settings="LATENCY_ACTION_SETTINGS",R.tenx="LATENCY_ACTION_TENX",R.video_to_ad="LATENCY_ACTION_VIDEO_TO_AD",R.watch="LATENCY_ACTION_WATCH",R.watch_it_again="LATENCY_ACTION_KIDS_WATCH_IT_AGAIN",R["watch,watch7"]="LATENCY_ACTION_WATCH",R["watch,watch7_html5"]="LATENCY_ACTION_WATCH",
R["watch,watch7ad"]="LATENCY_ACTION_WATCH",R["watch,watch7ad_html5"]="LATENCY_ACTION_WATCH",R.wn_comments="LATENCY_ACTION_LOAD_COMMENTS",R.ww_rqs="LATENCY_ACTION_WHO_IS_WATCHING",R["video.analytics"]="LATENCY_ACTION_CREATOR_VIDEO_ANALYTICS",R["video.comments"]="LATENCY_ACTION_CREATOR_VIDEO_COMMENTS",R["video.edit"]="LATENCY_ACTION_CREATOR_VIDEO_EDIT",R["video.editor"]="LATENCY_ACTION_CREATOR_VIDEO_VIDEO_EDITOR",R["video.editor_async"]="LATENCY_ACTION_CREATOR_VIDEO_VIDEO_EDITOR_ASYNC",R["video.live_settings"]=
"LATENCY_ACTION_CREATOR_VIDEO_LIVE_SETTINGS",R["video.live_streaming"]="LATENCY_ACTION_CREATOR_VIDEO_LIVE_STREAMING",R["video.monetization"]="LATENCY_ACTION_CREATOR_VIDEO_MONETIZATION",R["video.translations"]="LATENCY_ACTION_CREATOR_VIDEO_TRANSLATIONS",R.voice_assistant="LATENCY_ACTION_VOICE_ASSISTANT",R.cast_load_by_entity_to_watch="LATENCY_ACTION_CAST_LOAD_BY_ENTITY_TO_WATCH",R.networkless_performance="LATENCY_ACTION_NETWORKLESS_PERFORMANCE",R),T={},Dr=(T.ad_allowed="adTypesAllowed",T.yt_abt="adBreakType",
T.ad_cpn="adClientPlaybackNonce",T.ad_docid="adVideoId",T.yt_ad_an="adNetworks",T.ad_at="adType",T.aida="appInstallDataAgeMs",T.browse_id="browseId",T.p="httpProtocol",T.t="transportProtocol",T.cs="commandSource",T.cpn="clientPlaybackNonce",T.ccs="creatorInfo.creatorCanaryState",T.ctop="creatorInfo.topEntityType",T.csn="clientScreenNonce",T.docid="videoId",T.GetHome_rid="requestIds",T.GetSearch_rid="requestIds",T.GetPlayer_rid="requestIds",T.GetWatchNext_rid="requestIds",T.GetBrowse_rid="requestIds",
T.GetLibrary_rid="requestIds",T.is_continuation="isContinuation",T.is_nav="isNavigation",T.b_p="kabukiInfo.browseParams",T.is_prefetch="kabukiInfo.isPrefetch",T.is_secondary_nav="kabukiInfo.isSecondaryNav",T.nav_type="kabukiInfo.navigationType",T.prev_browse_id="kabukiInfo.prevBrowseId",T.query_source="kabukiInfo.querySource",T.voz_type="kabukiInfo.vozType",T.yt_lt="loadType",T.mver="creatorInfo.measurementVersion",T.yt_ad="isMonetized",T.nr="webInfo.navigationReason",T.nrsu="navigationRequestedSameUrl",
T.pnt="performanceNavigationTiming",T.prt="playbackRequiresTap",T.plt="playerInfo.playbackType",T.pis="playerInfo.playerInitializedState",T.paused="playerInfo.isPausedOnLoad",T.yt_pt="playerType",T.fmt="playerInfo.itag",T.yt_pl="watchInfo.isPlaylist",T.yt_pre="playerInfo.preloadType",T.yt_ad_pr="prerollAllowed",T.pa="previousAction",T.yt_red="isRedSubscriber",T.rce="mwebInfo.responseContentEncoding",T.rc="resourceInfo.resourceCache",T.scrh="screenHeight",T.scrw="screenWidth",T.st="serverTimeMs",T.ssdm=
"shellStartupDurationMs",T.br_trs="tvInfo.bedrockTriggerState",T.kebqat="kabukiInfo.earlyBrowseRequestInfo.abandonmentType",T.kebqa="kabukiInfo.earlyBrowseRequestInfo.adopted",T.label="tvInfo.label",T.is_mdx="tvInfo.isMdx",T.preloaded="tvInfo.isPreloaded",T.aac_type="tvInfo.authAccessCredentialType",T.upg_player_vis="playerInfo.visibilityState",T.query="unpluggedInfo.query",T.upg_chip_ids_string="unpluggedInfo.upgChipIdsString",T.yt_vst="videoStreamType",T.vph="viewportHeight",T.vpw="viewportWidth",
T.yt_vis="isVisible",T.rcl="mwebInfo.responseContentLength",T.GetSettings_rid="requestIds",T.GetTrending_rid="requestIds",T.GetMusicSearchSuggestions_rid="requestIds",T.REQUEST_ID="requestIds",T),Er="isContinuation isNavigation kabukiInfo.earlyBrowseRequestInfo.adopted kabukiInfo.isPrefetch kabukiInfo.isSecondaryNav isMonetized navigationRequestedSameUrl performanceNavigationTiming playerInfo.isPausedOnLoad prerollAllowed isRedSubscriber tvInfo.isMdx tvInfo.isPreloaded isVisible watchInfo.isPlaylist playbackRequiresTap".split(" "),
Fr={},Gr=(Fr.ccs="CANARY_STATE_",Fr.mver="MEASUREMENT_VERSION_",Fr.pis="PLAYER_INITIALIZED_STATE_",Fr.yt_pt="LATENCY_PLAYER_",Fr.pa="LATENCY_ACTION_",Fr.ctop="TOP_ENTITY_TYPE_",Fr.yt_vst="VIDEO_STREAM_TYPE_",Fr),Hr="all_vc ap aq c cbr cbrand cbrver cmodel cos cosver cplatform ctheme cver ei l_an l_mm plid srt yt_fss yt_li vpst vpni2 vpil2 icrc icrt pa GetAccountOverview_rid GetHistory_rid cmt d_vpct d_vpnfi d_vpni nsru pc pfa pfeh pftr pnc prerender psc rc start tcrt tcrc ssr vpr vps yt_abt yt_fn yt_fs yt_pft yt_pre yt_pt yt_pvis ytu_pvis yt_ref yt_sts tds".split(" ");
function Ir(a){return Cr[a]||"LATENCY_ACTION_UNKNOWN"}
function Jr(a,b,c){c=ur(c);if(c.gelInfos)c.gelInfos[a]=!0;else{var d={};c.gelInfos=(d[a]=!0,d)}if(a.match("_rid")){var e=a.split("_rid")[0];a="REQUEST_ID"}if(a in Dr){c=Dr[a];0<=cb(Er,c)&&(b=!!b);a in Gr&&"string"===typeof b&&(b=Gr[a]+b.toUpperCase());a=b;b=c.split(".");for(var f=d={},g=0;g<b.length-1;g++){var h=b[g];f[h]={};f=f[h]}f[b[b.length-1]]="requestIds"===c?[{id:a,endpoint:e}]:a;return cr({},d)}0<=cb(Hr,a)||Lp(new hk("Unknown label logged with GEL CSI",a))}
;var U={LATENCY_ACTION_KIDS_PROFILE_SWITCHER:90,LATENCY_ACTION_OFFLINE_THUMBNAIL_TRANSFER:100,LATENCY_ACTION_CREATOR_VIDEO_VIDEO_EDITOR_ASYNC:46,LATENCY_ACTION_CREATOR_VIDEO_VIDEO_EDITOR:37,LATENCY_ACTION_SPINNER_DISPLAYED:14,LATENCY_ACTION_PLAYABILITY_CHECK:10,LATENCY_ACTION_PROCESS:9,LATENCY_ACTION_APP_STARTUP:5,LATENCY_ACTION_LOG_PAYMENT_SERVER_ANALYTICS_RPC:173,LATENCY_ACTION_GET_PAYMENT_INSTRUMENTS_PARAMS_RPC:172,LATENCY_ACTION_GET_FIX_INSTRUMENT_PARAMS_RPC:171,LATENCY_ACTION_RESUME_SUBSCRIPTION_RPC:170,
LATENCY_ACTION_PAUSE_SUBSCRIPTION_RPC:169,LATENCY_ACTION_GET_OFFLINE_UPSELL_RPC:168,LATENCY_ACTION_GET_OFFERS_RPC:167,LATENCY_ACTION_GET_CANCELLATION_YT_FLOW_RPC:166,LATENCY_ACTION_GET_CANCELLATION_FLOW_RPC:165,LATENCY_ACTION_UPDATE_CROSS_DEVICE_OFFLINE_STATE_RPC:164,LATENCY_ACTION_GET_OFFER_DETAILS_RPC:163,LATENCY_ACTION_CANCEL_RECURRENCE_TRANSACTION_RPC:162,LATENCY_ACTION_GET_TIP_MODULE_RPC:161,LATENCY_ACTION_HANDLE_TRANSACTION_RPC:160,LATENCY_ACTION_COMPLETE_TRANSACTION_RPC:159,LATENCY_ACTION_GET_CART_RPC:158,
LATENCY_ACTION_THUMBNAIL_FETCH:156,LATENCY_ACTION_ABANDONED_DIRECT_PLAYBACK:154,LATENCY_ACTION_SHARE_VIDEO:153,LATENCY_ACTION_AD_TO_VIDEO_INT:152,LATENCY_ACTION_ABANDONED_BROWSE:151,LATENCY_ACTION_PLAYER_ROTATION:150,LATENCY_ACTION_SHOPPING_IN_APP:124,LATENCY_ACTION_PLAYER_ATTESTATION:121,LATENCY_ACTION_PLAYER_SEEK:119,LATENCY_ACTION_SUPER_STICKER_BUY_FLOW:114,LATENCY_ACTION_BLOCKS_PERFORMANCE:148,LATENCY_ACTION_ASSISTANT_QUERY:138,LATENCY_ACTION_ASSISTANT_SETTINGS:137,LATENCY_ACTION_ENTITY_KEY_DESERIALIZATION_PERF:129,
LATENCY_ACTION_ENTITY_KEY_SERIALIZATION_PERF:128,LATENCY_ACTION_PROOF_OF_ORIGIN_TOKEN_CREATE:127,LATENCY_ACTION_EMBEDS_SDK_INITIALIZATION:123,LATENCY_ACTION_NETWORKLESS_PERFORMANCE:122,LATENCY_ACTION_DOWNLOADS_EXPANSION:133,LATENCY_ACTION_ENTITY_TRANSFORM:131,LATENCY_ACTION_DOWNLOADS_COMPATIBILITY_LAYER:96,LATENCY_ACTION_EMBEDS_SET_VIDEO:95,LATENCY_ACTION_SETTINGS:93,LATENCY_ACTION_ABANDONED_STARTUP:81,LATENCY_ACTION_MEDIA_BROWSER_ALARM_PLAY:80,LATENCY_ACTION_MEDIA_BROWSER_SEARCH:79,LATENCY_ACTION_MEDIA_BROWSER_LOAD_TREE:78,
LATENCY_ACTION_WHO_IS_WATCHING:77,LATENCY_ACTION_CAST_LOAD_BY_ENTITY_TO_WATCH:76,LATENCY_ACTION_LITE_SWITCH_ACCOUNT:73,LATENCY_ACTION_ELEMENTS_PERFORMANCE:70,LATENCY_ACTION_LOCATION_SIGNAL_COLLECTION:69,LATENCY_ACTION_MODIFY_CHANNEL_NOTIFICATION:65,LATENCY_ACTION_OFFLINE_STORE_START:61,LATENCY_ACTION_REEL_EDITOR:58,LATENCY_ACTION_CHANNEL_SUBSCRIBE:56,LATENCY_ACTION_CHANNEL_PREVIEW:55,LATENCY_ACTION_PREFETCH:52,LATENCY_ACTION_ABANDONED_WATCH:45,LATENCY_ACTION_LOAD_COMMENT_REPLIES:26,LATENCY_ACTION_LOAD_COMMENTS:25,
LATENCY_ACTION_EDIT_COMMENT:24,LATENCY_ACTION_NEW_COMMENT:23,LATENCY_ACTION_OFFLINE_SHARING_RECEIVER_PAIRING:19,LATENCY_ACTION_EMBED:18,LATENCY_ACTION_MDX_LAUNCH:15,LATENCY_ACTION_RESOLVE_URL:13,LATENCY_ACTION_CAST_SPLASH:149,LATENCY_ACTION_MDX_CAST:120,LATENCY_ACTION_MDX_COMMAND:12,LATENCY_ACTION_REEL_SELECT_SEGMENT:136,LATENCY_ACTION_ACCELERATED_EFFECTS:145,LATENCY_ACTION_UPLOAD_AUDIO_MIXER:147,LATENCY_ACTION_SHORTS_CLIENT_SIDE_RENDERING:157,LATENCY_ACTION_SHORTS_SEG_IMP_TRANSCODING:146,LATENCY_ACTION_SHORTS_AUDIO_PICKER_PLAYBACK:130,
LATENCY_ACTION_SHORTS_WAVEFORM_DOWNLOAD:125,LATENCY_ACTION_SHORTS_VIDEO_INGESTION:155,LATENCY_ACTION_SHORTS_GALLERY:107,LATENCY_ACTION_SHORTS_TRIM:105,LATENCY_ACTION_SHORTS_EDIT:104,LATENCY_ACTION_SHORTS_CAMERA:103,LATENCY_ACTION_PARENT_TOOLS_DASHBOARD:102,LATENCY_ACTION_PARENT_TOOLS_COLLECTION:101,LATENCY_ACTION_MUSIC_LOAD_RECOMMENDED_MEDIA_ITEMS:116,LATENCY_ACTION_MUSIC_LOAD_MEDIA_ITEMS:115,LATENCY_ACTION_MUSIC_ALBUM_DETAIL:72,LATENCY_ACTION_MUSIC_PLAYLIST_DETAIL:71,LATENCY_ACTION_CHIPS:68,LATENCY_ACTION_SEARCH_ZERO_STATE:67,
LATENCY_ACTION_LIVE_PAGINATION:117,LATENCY_ACTION_LIVE:20,LATENCY_ACTION_PREBUFFER:40,LATENCY_ACTION_TENX:39,LATENCY_ACTION_KIDS_PROFILE_SETTINGS:94,LATENCY_ACTION_KIDS_WATCH_IT_AGAIN:92,LATENCY_ACTION_KIDS_SECRET_CODE:91,LATENCY_ACTION_KIDS_PARENT_PROFILE_SETTINGS:89,LATENCY_ACTION_KIDS_ONBOARDING:88,LATENCY_ACTION_KIDS_VOICE_SEARCH:82,LATENCY_ACTION_KIDS_CURATED_COLLECTION:62,LATENCY_ACTION_KIDS_LIBRARY:53,LATENCY_ACTION_CREATOR_VIDEO_TRANSLATIONS:38,LATENCY_ACTION_CREATOR_VIDEO_MONETIZATION:74,
LATENCY_ACTION_CREATOR_VIDEO_LIVE_STREAMING:141,LATENCY_ACTION_CREATOR_VIDEO_LIVE_SETTINGS:142,LATENCY_ACTION_CREATOR_VIDEO_EDITOR_ASYNC:51,LATENCY_ACTION_CREATOR_VIDEO_EDITOR:50,LATENCY_ACTION_CREATOR_VIDEO_EDIT:36,LATENCY_ACTION_CREATOR_VIDEO_COMMENTS:34,LATENCY_ACTION_CREATOR_VIDEO_ANALYTICS:33,LATENCY_ACTION_CREATOR_POST_LIST:112,LATENCY_ACTION_CREATOR_POST_EDIT:110,LATENCY_ACTION_CREATOR_POST_COMMENTS:111,LATENCY_ACTION_CREATOR_LIVE_STREAMING:108,LATENCY_ACTION_CREATOR_DIALOG_VIDEO_COPYRIGHT:174,
LATENCY_ACTION_CREATOR_DIALOG_UPLOADS:86,LATENCY_ACTION_CREATOR_DIALOG_COPYRIGHT_STRIKES:87,LATENCY_ACTION_CREATOR_CHANNEL_VIDEOS:32,LATENCY_ACTION_CREATOR_CHANNEL_TRANSLATIONS:48,LATENCY_ACTION_CREATOR_CHANNEL_PLAYLISTS:139,LATENCY_ACTION_CREATOR_CHANNEL_MUSIC:99,LATENCY_ACTION_CREATOR_CHANNEL_MONETIZATION:43,LATENCY_ACTION_CREATOR_CHANNEL_EDITING:113,LATENCY_ACTION_CREATOR_CHANNEL_DASHBOARD:49,LATENCY_ACTION_CREATOR_CHANNEL_COPYRIGHT:44,LATENCY_ACTION_CREATOR_CHANNEL_COMMENTS:66,LATENCY_ACTION_CREATOR_CHANNEL_ANALYTICS:31,
LATENCY_ACTION_CREATOR_ARTIST_PROFILE:85,LATENCY_ACTION_CREATOR_ARTIST_CONCERTS:84,LATENCY_ACTION_CREATOR_ARTIST_ANALYTICS:83,LATENCY_ACTION_CREATOR_ANALYTICS_EXPLORE:140,LATENCY_ACTION_STORYBOARD_THUMBNAILS:118,LATENCY_ACTION_SEARCH_THUMBNAILS:59,LATENCY_ACTION_ON_DEVICE_MODEL_DOWNLOAD:54,LATENCY_ACTION_VOICE_ASSISTANT:47,LATENCY_ACTION_SEARCH_UI:35,LATENCY_ACTION_SUGGEST:30,LATENCY_ACTION_AUTO_SEARCH:126,LATENCY_ACTION_DOWNLOADS:98,LATENCY_ACTION_EXPLORE:75,LATENCY_ACTION_VIDEO_LIST:63,LATENCY_ACTION_HOME_RESUME:60,
LATENCY_ACTION_SUBSCRIPTIONS_LIST:57,LATENCY_ACTION_THUMBNAIL_LOAD:42,LATENCY_ACTION_FIRST_THUMBNAIL_LOAD:29,LATENCY_ACTION_SUBSCRIPTIONS_FEED:109,LATENCY_ACTION_SUBSCRIPTIONS:28,LATENCY_ACTION_TRENDING:27,LATENCY_ACTION_LIBRARY:21,LATENCY_ACTION_VIDEO_THUMBNAIL:8,LATENCY_ACTION_SHOW_MORE:7,LATENCY_ACTION_VIDEO_PREVIEW:6,LATENCY_ACTION_PREBUFFER_VIDEO:144,LATENCY_ACTION_PREFETCH_VIDEO:143,LATENCY_ACTION_DIRECT_PLAYBACK:132,LATENCY_ACTION_REEL_WATCH:41,LATENCY_ACTION_AD_TO_AD:22,LATENCY_ACTION_VIDEO_TO_AD:17,
LATENCY_ACTION_AD_TO_VIDEO:16,LATENCY_ACTION_ONBOARDING:135,LATENCY_ACTION_LOGIN:97,LATENCY_ACTION_BROWSE:11,LATENCY_ACTION_CHANNELS:4,LATENCY_ACTION_WATCH:3,LATENCY_ACTION_RESULTS:2,LATENCY_ACTION_HOME:1,LATENCY_ACTION_STARTUP:106,LATENCY_ACTION_UNKNOWN:0};U[U.LATENCY_ACTION_KIDS_PROFILE_SWITCHER]="LATENCY_ACTION_KIDS_PROFILE_SWITCHER";U[U.LATENCY_ACTION_OFFLINE_THUMBNAIL_TRANSFER]="LATENCY_ACTION_OFFLINE_THUMBNAIL_TRANSFER";U[U.LATENCY_ACTION_CREATOR_VIDEO_VIDEO_EDITOR_ASYNC]="LATENCY_ACTION_CREATOR_VIDEO_VIDEO_EDITOR_ASYNC";
U[U.LATENCY_ACTION_CREATOR_VIDEO_VIDEO_EDITOR]="LATENCY_ACTION_CREATOR_VIDEO_VIDEO_EDITOR";U[U.LATENCY_ACTION_SPINNER_DISPLAYED]="LATENCY_ACTION_SPINNER_DISPLAYED";U[U.LATENCY_ACTION_PLAYABILITY_CHECK]="LATENCY_ACTION_PLAYABILITY_CHECK";U[U.LATENCY_ACTION_PROCESS]="LATENCY_ACTION_PROCESS";U[U.LATENCY_ACTION_APP_STARTUP]="LATENCY_ACTION_APP_STARTUP";U[U.LATENCY_ACTION_LOG_PAYMENT_SERVER_ANALYTICS_RPC]="LATENCY_ACTION_LOG_PAYMENT_SERVER_ANALYTICS_RPC";
U[U.LATENCY_ACTION_GET_PAYMENT_INSTRUMENTS_PARAMS_RPC]="LATENCY_ACTION_GET_PAYMENT_INSTRUMENTS_PARAMS_RPC";U[U.LATENCY_ACTION_GET_FIX_INSTRUMENT_PARAMS_RPC]="LATENCY_ACTION_GET_FIX_INSTRUMENT_PARAMS_RPC";U[U.LATENCY_ACTION_RESUME_SUBSCRIPTION_RPC]="LATENCY_ACTION_RESUME_SUBSCRIPTION_RPC";U[U.LATENCY_ACTION_PAUSE_SUBSCRIPTION_RPC]="LATENCY_ACTION_PAUSE_SUBSCRIPTION_RPC";U[U.LATENCY_ACTION_GET_OFFLINE_UPSELL_RPC]="LATENCY_ACTION_GET_OFFLINE_UPSELL_RPC";U[U.LATENCY_ACTION_GET_OFFERS_RPC]="LATENCY_ACTION_GET_OFFERS_RPC";
U[U.LATENCY_ACTION_GET_CANCELLATION_YT_FLOW_RPC]="LATENCY_ACTION_GET_CANCELLATION_YT_FLOW_RPC";U[U.LATENCY_ACTION_GET_CANCELLATION_FLOW_RPC]="LATENCY_ACTION_GET_CANCELLATION_FLOW_RPC";U[U.LATENCY_ACTION_UPDATE_CROSS_DEVICE_OFFLINE_STATE_RPC]="LATENCY_ACTION_UPDATE_CROSS_DEVICE_OFFLINE_STATE_RPC";U[U.LATENCY_ACTION_GET_OFFER_DETAILS_RPC]="LATENCY_ACTION_GET_OFFER_DETAILS_RPC";U[U.LATENCY_ACTION_CANCEL_RECURRENCE_TRANSACTION_RPC]="LATENCY_ACTION_CANCEL_RECURRENCE_TRANSACTION_RPC";
U[U.LATENCY_ACTION_GET_TIP_MODULE_RPC]="LATENCY_ACTION_GET_TIP_MODULE_RPC";U[U.LATENCY_ACTION_HANDLE_TRANSACTION_RPC]="LATENCY_ACTION_HANDLE_TRANSACTION_RPC";U[U.LATENCY_ACTION_COMPLETE_TRANSACTION_RPC]="LATENCY_ACTION_COMPLETE_TRANSACTION_RPC";U[U.LATENCY_ACTION_GET_CART_RPC]="LATENCY_ACTION_GET_CART_RPC";U[U.LATENCY_ACTION_THUMBNAIL_FETCH]="LATENCY_ACTION_THUMBNAIL_FETCH";U[U.LATENCY_ACTION_ABANDONED_DIRECT_PLAYBACK]="LATENCY_ACTION_ABANDONED_DIRECT_PLAYBACK";U[U.LATENCY_ACTION_SHARE_VIDEO]="LATENCY_ACTION_SHARE_VIDEO";
U[U.LATENCY_ACTION_AD_TO_VIDEO_INT]="LATENCY_ACTION_AD_TO_VIDEO_INT";U[U.LATENCY_ACTION_ABANDONED_BROWSE]="LATENCY_ACTION_ABANDONED_BROWSE";U[U.LATENCY_ACTION_PLAYER_ROTATION]="LATENCY_ACTION_PLAYER_ROTATION";U[U.LATENCY_ACTION_SHOPPING_IN_APP]="LATENCY_ACTION_SHOPPING_IN_APP";U[U.LATENCY_ACTION_PLAYER_ATTESTATION]="LATENCY_ACTION_PLAYER_ATTESTATION";U[U.LATENCY_ACTION_PLAYER_SEEK]="LATENCY_ACTION_PLAYER_SEEK";U[U.LATENCY_ACTION_SUPER_STICKER_BUY_FLOW]="LATENCY_ACTION_SUPER_STICKER_BUY_FLOW";
U[U.LATENCY_ACTION_BLOCKS_PERFORMANCE]="LATENCY_ACTION_BLOCKS_PERFORMANCE";U[U.LATENCY_ACTION_ASSISTANT_QUERY]="LATENCY_ACTION_ASSISTANT_QUERY";U[U.LATENCY_ACTION_ASSISTANT_SETTINGS]="LATENCY_ACTION_ASSISTANT_SETTINGS";U[U.LATENCY_ACTION_ENTITY_KEY_DESERIALIZATION_PERF]="LATENCY_ACTION_ENTITY_KEY_DESERIALIZATION_PERF";U[U.LATENCY_ACTION_ENTITY_KEY_SERIALIZATION_PERF]="LATENCY_ACTION_ENTITY_KEY_SERIALIZATION_PERF";U[U.LATENCY_ACTION_PROOF_OF_ORIGIN_TOKEN_CREATE]="LATENCY_ACTION_PROOF_OF_ORIGIN_TOKEN_CREATE";
U[U.LATENCY_ACTION_EMBEDS_SDK_INITIALIZATION]="LATENCY_ACTION_EMBEDS_SDK_INITIALIZATION";U[U.LATENCY_ACTION_NETWORKLESS_PERFORMANCE]="LATENCY_ACTION_NETWORKLESS_PERFORMANCE";U[U.LATENCY_ACTION_DOWNLOADS_EXPANSION]="LATENCY_ACTION_DOWNLOADS_EXPANSION";U[U.LATENCY_ACTION_ENTITY_TRANSFORM]="LATENCY_ACTION_ENTITY_TRANSFORM";U[U.LATENCY_ACTION_DOWNLOADS_COMPATIBILITY_LAYER]="LATENCY_ACTION_DOWNLOADS_COMPATIBILITY_LAYER";U[U.LATENCY_ACTION_EMBEDS_SET_VIDEO]="LATENCY_ACTION_EMBEDS_SET_VIDEO";
U[U.LATENCY_ACTION_SETTINGS]="LATENCY_ACTION_SETTINGS";U[U.LATENCY_ACTION_ABANDONED_STARTUP]="LATENCY_ACTION_ABANDONED_STARTUP";U[U.LATENCY_ACTION_MEDIA_BROWSER_ALARM_PLAY]="LATENCY_ACTION_MEDIA_BROWSER_ALARM_PLAY";U[U.LATENCY_ACTION_MEDIA_BROWSER_SEARCH]="LATENCY_ACTION_MEDIA_BROWSER_SEARCH";U[U.LATENCY_ACTION_MEDIA_BROWSER_LOAD_TREE]="LATENCY_ACTION_MEDIA_BROWSER_LOAD_TREE";U[U.LATENCY_ACTION_WHO_IS_WATCHING]="LATENCY_ACTION_WHO_IS_WATCHING";U[U.LATENCY_ACTION_CAST_LOAD_BY_ENTITY_TO_WATCH]="LATENCY_ACTION_CAST_LOAD_BY_ENTITY_TO_WATCH";
U[U.LATENCY_ACTION_LITE_SWITCH_ACCOUNT]="LATENCY_ACTION_LITE_SWITCH_ACCOUNT";U[U.LATENCY_ACTION_ELEMENTS_PERFORMANCE]="LATENCY_ACTION_ELEMENTS_PERFORMANCE";U[U.LATENCY_ACTION_LOCATION_SIGNAL_COLLECTION]="LATENCY_ACTION_LOCATION_SIGNAL_COLLECTION";U[U.LATENCY_ACTION_MODIFY_CHANNEL_NOTIFICATION]="LATENCY_ACTION_MODIFY_CHANNEL_NOTIFICATION";U[U.LATENCY_ACTION_OFFLINE_STORE_START]="LATENCY_ACTION_OFFLINE_STORE_START";U[U.LATENCY_ACTION_REEL_EDITOR]="LATENCY_ACTION_REEL_EDITOR";
U[U.LATENCY_ACTION_CHANNEL_SUBSCRIBE]="LATENCY_ACTION_CHANNEL_SUBSCRIBE";U[U.LATENCY_ACTION_CHANNEL_PREVIEW]="LATENCY_ACTION_CHANNEL_PREVIEW";U[U.LATENCY_ACTION_PREFETCH]="LATENCY_ACTION_PREFETCH";U[U.LATENCY_ACTION_ABANDONED_WATCH]="LATENCY_ACTION_ABANDONED_WATCH";U[U.LATENCY_ACTION_LOAD_COMMENT_REPLIES]="LATENCY_ACTION_LOAD_COMMENT_REPLIES";U[U.LATENCY_ACTION_LOAD_COMMENTS]="LATENCY_ACTION_LOAD_COMMENTS";U[U.LATENCY_ACTION_EDIT_COMMENT]="LATENCY_ACTION_EDIT_COMMENT";
U[U.LATENCY_ACTION_NEW_COMMENT]="LATENCY_ACTION_NEW_COMMENT";U[U.LATENCY_ACTION_OFFLINE_SHARING_RECEIVER_PAIRING]="LATENCY_ACTION_OFFLINE_SHARING_RECEIVER_PAIRING";U[U.LATENCY_ACTION_EMBED]="LATENCY_ACTION_EMBED";U[U.LATENCY_ACTION_MDX_LAUNCH]="LATENCY_ACTION_MDX_LAUNCH";U[U.LATENCY_ACTION_RESOLVE_URL]="LATENCY_ACTION_RESOLVE_URL";U[U.LATENCY_ACTION_CAST_SPLASH]="LATENCY_ACTION_CAST_SPLASH";U[U.LATENCY_ACTION_MDX_CAST]="LATENCY_ACTION_MDX_CAST";U[U.LATENCY_ACTION_MDX_COMMAND]="LATENCY_ACTION_MDX_COMMAND";
U[U.LATENCY_ACTION_REEL_SELECT_SEGMENT]="LATENCY_ACTION_REEL_SELECT_SEGMENT";U[U.LATENCY_ACTION_ACCELERATED_EFFECTS]="LATENCY_ACTION_ACCELERATED_EFFECTS";U[U.LATENCY_ACTION_UPLOAD_AUDIO_MIXER]="LATENCY_ACTION_UPLOAD_AUDIO_MIXER";U[U.LATENCY_ACTION_SHORTS_CLIENT_SIDE_RENDERING]="LATENCY_ACTION_SHORTS_CLIENT_SIDE_RENDERING";U[U.LATENCY_ACTION_SHORTS_SEG_IMP_TRANSCODING]="LATENCY_ACTION_SHORTS_SEG_IMP_TRANSCODING";U[U.LATENCY_ACTION_SHORTS_AUDIO_PICKER_PLAYBACK]="LATENCY_ACTION_SHORTS_AUDIO_PICKER_PLAYBACK";
U[U.LATENCY_ACTION_SHORTS_WAVEFORM_DOWNLOAD]="LATENCY_ACTION_SHORTS_WAVEFORM_DOWNLOAD";U[U.LATENCY_ACTION_SHORTS_VIDEO_INGESTION]="LATENCY_ACTION_SHORTS_VIDEO_INGESTION";U[U.LATENCY_ACTION_SHORTS_GALLERY]="LATENCY_ACTION_SHORTS_GALLERY";U[U.LATENCY_ACTION_SHORTS_TRIM]="LATENCY_ACTION_SHORTS_TRIM";U[U.LATENCY_ACTION_SHORTS_EDIT]="LATENCY_ACTION_SHORTS_EDIT";U[U.LATENCY_ACTION_SHORTS_CAMERA]="LATENCY_ACTION_SHORTS_CAMERA";U[U.LATENCY_ACTION_PARENT_TOOLS_DASHBOARD]="LATENCY_ACTION_PARENT_TOOLS_DASHBOARD";
U[U.LATENCY_ACTION_PARENT_TOOLS_COLLECTION]="LATENCY_ACTION_PARENT_TOOLS_COLLECTION";U[U.LATENCY_ACTION_MUSIC_LOAD_RECOMMENDED_MEDIA_ITEMS]="LATENCY_ACTION_MUSIC_LOAD_RECOMMENDED_MEDIA_ITEMS";U[U.LATENCY_ACTION_MUSIC_LOAD_MEDIA_ITEMS]="LATENCY_ACTION_MUSIC_LOAD_MEDIA_ITEMS";U[U.LATENCY_ACTION_MUSIC_ALBUM_DETAIL]="LATENCY_ACTION_MUSIC_ALBUM_DETAIL";U[U.LATENCY_ACTION_MUSIC_PLAYLIST_DETAIL]="LATENCY_ACTION_MUSIC_PLAYLIST_DETAIL";U[U.LATENCY_ACTION_CHIPS]="LATENCY_ACTION_CHIPS";
U[U.LATENCY_ACTION_SEARCH_ZERO_STATE]="LATENCY_ACTION_SEARCH_ZERO_STATE";U[U.LATENCY_ACTION_LIVE_PAGINATION]="LATENCY_ACTION_LIVE_PAGINATION";U[U.LATENCY_ACTION_LIVE]="LATENCY_ACTION_LIVE";U[U.LATENCY_ACTION_PREBUFFER]="LATENCY_ACTION_PREBUFFER";U[U.LATENCY_ACTION_TENX]="LATENCY_ACTION_TENX";U[U.LATENCY_ACTION_KIDS_PROFILE_SETTINGS]="LATENCY_ACTION_KIDS_PROFILE_SETTINGS";U[U.LATENCY_ACTION_KIDS_WATCH_IT_AGAIN]="LATENCY_ACTION_KIDS_WATCH_IT_AGAIN";U[U.LATENCY_ACTION_KIDS_SECRET_CODE]="LATENCY_ACTION_KIDS_SECRET_CODE";
U[U.LATENCY_ACTION_KIDS_PARENT_PROFILE_SETTINGS]="LATENCY_ACTION_KIDS_PARENT_PROFILE_SETTINGS";U[U.LATENCY_ACTION_KIDS_ONBOARDING]="LATENCY_ACTION_KIDS_ONBOARDING";U[U.LATENCY_ACTION_KIDS_VOICE_SEARCH]="LATENCY_ACTION_KIDS_VOICE_SEARCH";U[U.LATENCY_ACTION_KIDS_CURATED_COLLECTION]="LATENCY_ACTION_KIDS_CURATED_COLLECTION";U[U.LATENCY_ACTION_KIDS_LIBRARY]="LATENCY_ACTION_KIDS_LIBRARY";U[U.LATENCY_ACTION_CREATOR_VIDEO_TRANSLATIONS]="LATENCY_ACTION_CREATOR_VIDEO_TRANSLATIONS";
U[U.LATENCY_ACTION_CREATOR_VIDEO_MONETIZATION]="LATENCY_ACTION_CREATOR_VIDEO_MONETIZATION";U[U.LATENCY_ACTION_CREATOR_VIDEO_LIVE_STREAMING]="LATENCY_ACTION_CREATOR_VIDEO_LIVE_STREAMING";U[U.LATENCY_ACTION_CREATOR_VIDEO_LIVE_SETTINGS]="LATENCY_ACTION_CREATOR_VIDEO_LIVE_SETTINGS";U[U.LATENCY_ACTION_CREATOR_VIDEO_EDITOR_ASYNC]="LATENCY_ACTION_CREATOR_VIDEO_EDITOR_ASYNC";U[U.LATENCY_ACTION_CREATOR_VIDEO_EDITOR]="LATENCY_ACTION_CREATOR_VIDEO_EDITOR";U[U.LATENCY_ACTION_CREATOR_VIDEO_EDIT]="LATENCY_ACTION_CREATOR_VIDEO_EDIT";
U[U.LATENCY_ACTION_CREATOR_VIDEO_COMMENTS]="LATENCY_ACTION_CREATOR_VIDEO_COMMENTS";U[U.LATENCY_ACTION_CREATOR_VIDEO_ANALYTICS]="LATENCY_ACTION_CREATOR_VIDEO_ANALYTICS";U[U.LATENCY_ACTION_CREATOR_POST_LIST]="LATENCY_ACTION_CREATOR_POST_LIST";U[U.LATENCY_ACTION_CREATOR_POST_EDIT]="LATENCY_ACTION_CREATOR_POST_EDIT";U[U.LATENCY_ACTION_CREATOR_POST_COMMENTS]="LATENCY_ACTION_CREATOR_POST_COMMENTS";U[U.LATENCY_ACTION_CREATOR_LIVE_STREAMING]="LATENCY_ACTION_CREATOR_LIVE_STREAMING";
U[U.LATENCY_ACTION_CREATOR_DIALOG_VIDEO_COPYRIGHT]="LATENCY_ACTION_CREATOR_DIALOG_VIDEO_COPYRIGHT";U[U.LATENCY_ACTION_CREATOR_DIALOG_UPLOADS]="LATENCY_ACTION_CREATOR_DIALOG_UPLOADS";U[U.LATENCY_ACTION_CREATOR_DIALOG_COPYRIGHT_STRIKES]="LATENCY_ACTION_CREATOR_DIALOG_COPYRIGHT_STRIKES";U[U.LATENCY_ACTION_CREATOR_CHANNEL_VIDEOS]="LATENCY_ACTION_CREATOR_CHANNEL_VIDEOS";U[U.LATENCY_ACTION_CREATOR_CHANNEL_TRANSLATIONS]="LATENCY_ACTION_CREATOR_CHANNEL_TRANSLATIONS";
U[U.LATENCY_ACTION_CREATOR_CHANNEL_PLAYLISTS]="LATENCY_ACTION_CREATOR_CHANNEL_PLAYLISTS";U[U.LATENCY_ACTION_CREATOR_CHANNEL_MUSIC]="LATENCY_ACTION_CREATOR_CHANNEL_MUSIC";U[U.LATENCY_ACTION_CREATOR_CHANNEL_MONETIZATION]="LATENCY_ACTION_CREATOR_CHANNEL_MONETIZATION";U[U.LATENCY_ACTION_CREATOR_CHANNEL_EDITING]="LATENCY_ACTION_CREATOR_CHANNEL_EDITING";U[U.LATENCY_ACTION_CREATOR_CHANNEL_DASHBOARD]="LATENCY_ACTION_CREATOR_CHANNEL_DASHBOARD";U[U.LATENCY_ACTION_CREATOR_CHANNEL_COPYRIGHT]="LATENCY_ACTION_CREATOR_CHANNEL_COPYRIGHT";
U[U.LATENCY_ACTION_CREATOR_CHANNEL_COMMENTS]="LATENCY_ACTION_CREATOR_CHANNEL_COMMENTS";U[U.LATENCY_ACTION_CREATOR_CHANNEL_ANALYTICS]="LATENCY_ACTION_CREATOR_CHANNEL_ANALYTICS";U[U.LATENCY_ACTION_CREATOR_ARTIST_PROFILE]="LATENCY_ACTION_CREATOR_ARTIST_PROFILE";U[U.LATENCY_ACTION_CREATOR_ARTIST_CONCERTS]="LATENCY_ACTION_CREATOR_ARTIST_CONCERTS";U[U.LATENCY_ACTION_CREATOR_ARTIST_ANALYTICS]="LATENCY_ACTION_CREATOR_ARTIST_ANALYTICS";U[U.LATENCY_ACTION_CREATOR_ANALYTICS_EXPLORE]="LATENCY_ACTION_CREATOR_ANALYTICS_EXPLORE";
U[U.LATENCY_ACTION_STORYBOARD_THUMBNAILS]="LATENCY_ACTION_STORYBOARD_THUMBNAILS";U[U.LATENCY_ACTION_SEARCH_THUMBNAILS]="LATENCY_ACTION_SEARCH_THUMBNAILS";U[U.LATENCY_ACTION_ON_DEVICE_MODEL_DOWNLOAD]="LATENCY_ACTION_ON_DEVICE_MODEL_DOWNLOAD";U[U.LATENCY_ACTION_VOICE_ASSISTANT]="LATENCY_ACTION_VOICE_ASSISTANT";U[U.LATENCY_ACTION_SEARCH_UI]="LATENCY_ACTION_SEARCH_UI";U[U.LATENCY_ACTION_SUGGEST]="LATENCY_ACTION_SUGGEST";U[U.LATENCY_ACTION_AUTO_SEARCH]="LATENCY_ACTION_AUTO_SEARCH";
U[U.LATENCY_ACTION_DOWNLOADS]="LATENCY_ACTION_DOWNLOADS";U[U.LATENCY_ACTION_EXPLORE]="LATENCY_ACTION_EXPLORE";U[U.LATENCY_ACTION_VIDEO_LIST]="LATENCY_ACTION_VIDEO_LIST";U[U.LATENCY_ACTION_HOME_RESUME]="LATENCY_ACTION_HOME_RESUME";U[U.LATENCY_ACTION_SUBSCRIPTIONS_LIST]="LATENCY_ACTION_SUBSCRIPTIONS_LIST";U[U.LATENCY_ACTION_THUMBNAIL_LOAD]="LATENCY_ACTION_THUMBNAIL_LOAD";U[U.LATENCY_ACTION_FIRST_THUMBNAIL_LOAD]="LATENCY_ACTION_FIRST_THUMBNAIL_LOAD";U[U.LATENCY_ACTION_SUBSCRIPTIONS_FEED]="LATENCY_ACTION_SUBSCRIPTIONS_FEED";
U[U.LATENCY_ACTION_SUBSCRIPTIONS]="LATENCY_ACTION_SUBSCRIPTIONS";U[U.LATENCY_ACTION_TRENDING]="LATENCY_ACTION_TRENDING";U[U.LATENCY_ACTION_LIBRARY]="LATENCY_ACTION_LIBRARY";U[U.LATENCY_ACTION_VIDEO_THUMBNAIL]="LATENCY_ACTION_VIDEO_THUMBNAIL";U[U.LATENCY_ACTION_SHOW_MORE]="LATENCY_ACTION_SHOW_MORE";U[U.LATENCY_ACTION_VIDEO_PREVIEW]="LATENCY_ACTION_VIDEO_PREVIEW";U[U.LATENCY_ACTION_PREBUFFER_VIDEO]="LATENCY_ACTION_PREBUFFER_VIDEO";U[U.LATENCY_ACTION_PREFETCH_VIDEO]="LATENCY_ACTION_PREFETCH_VIDEO";
U[U.LATENCY_ACTION_DIRECT_PLAYBACK]="LATENCY_ACTION_DIRECT_PLAYBACK";U[U.LATENCY_ACTION_REEL_WATCH]="LATENCY_ACTION_REEL_WATCH";U[U.LATENCY_ACTION_AD_TO_AD]="LATENCY_ACTION_AD_TO_AD";U[U.LATENCY_ACTION_VIDEO_TO_AD]="LATENCY_ACTION_VIDEO_TO_AD";U[U.LATENCY_ACTION_AD_TO_VIDEO]="LATENCY_ACTION_AD_TO_VIDEO";U[U.LATENCY_ACTION_ONBOARDING]="LATENCY_ACTION_ONBOARDING";U[U.LATENCY_ACTION_LOGIN]="LATENCY_ACTION_LOGIN";U[U.LATENCY_ACTION_BROWSE]="LATENCY_ACTION_BROWSE";U[U.LATENCY_ACTION_CHANNELS]="LATENCY_ACTION_CHANNELS";
U[U.LATENCY_ACTION_WATCH]="LATENCY_ACTION_WATCH";U[U.LATENCY_ACTION_RESULTS]="LATENCY_ACTION_RESULTS";U[U.LATENCY_ACTION_HOME]="LATENCY_ACTION_HOME";U[U.LATENCY_ACTION_STARTUP]="LATENCY_ACTION_STARTUP";U[U.LATENCY_ACTION_UNKNOWN]="LATENCY_ACTION_UNKNOWN";var Kr={LATENCY_NETWORK_MOBILE:2,LATENCY_NETWORK_WIFI:1,LATENCY_NETWORK_UNKNOWN:0};Kr[Kr.LATENCY_NETWORK_MOBILE]="LATENCY_NETWORK_MOBILE";Kr[Kr.LATENCY_NETWORK_WIFI]="LATENCY_NETWORK_WIFI";Kr[Kr.LATENCY_NETWORK_UNKNOWN]="LATENCY_NETWORK_UNKNOWN";
var X={CONN_INVALID:31,CONN_CELLULAR_5G_NSA:12,CONN_CELLULAR_5G_SA:11,CONN_WIFI_METERED:10,CONN_CELLULAR_5G:9,CONN_DISCO:8,CONN_CELLULAR_UNKNOWN:7,CONN_CELLULAR_4G:6,CONN_CELLULAR_3G:5,CONN_CELLULAR_2G:4,CONN_WIFI:3,CONN_NONE:2,CONN_UNKNOWN:1,CONN_DEFAULT:0};X[X.CONN_INVALID]="CONN_INVALID";X[X.CONN_CELLULAR_5G_NSA]="CONN_CELLULAR_5G_NSA";X[X.CONN_CELLULAR_5G_SA]="CONN_CELLULAR_5G_SA";X[X.CONN_WIFI_METERED]="CONN_WIFI_METERED";X[X.CONN_CELLULAR_5G]="CONN_CELLULAR_5G";X[X.CONN_DISCO]="CONN_DISCO";
X[X.CONN_CELLULAR_UNKNOWN]="CONN_CELLULAR_UNKNOWN";X[X.CONN_CELLULAR_4G]="CONN_CELLULAR_4G";X[X.CONN_CELLULAR_3G]="CONN_CELLULAR_3G";X[X.CONN_CELLULAR_2G]="CONN_CELLULAR_2G";X[X.CONN_WIFI]="CONN_WIFI";X[X.CONN_NONE]="CONN_NONE";X[X.CONN_UNKNOWN]="CONN_UNKNOWN";X[X.CONN_DEFAULT]="CONN_DEFAULT";
var Y={DETAILED_NETWORK_TYPE_NR_NSA:126,DETAILED_NETWORK_TYPE_NR_SA:125,DETAILED_NETWORK_TYPE_INTERNAL_WIFI_IMPAIRED:124,DETAILED_NETWORK_TYPE_APP_WIFI_HOTSPOT:123,DETAILED_NETWORK_TYPE_DISCONNECTED:122,DETAILED_NETWORK_TYPE_NON_MOBILE_UNKNOWN:121,DETAILED_NETWORK_TYPE_MOBILE_UNKNOWN:120,DETAILED_NETWORK_TYPE_WIMAX:119,DETAILED_NETWORK_TYPE_ETHERNET:118,DETAILED_NETWORK_TYPE_BLUETOOTH:117,DETAILED_NETWORK_TYPE_WIFI:116,DETAILED_NETWORK_TYPE_LTE:115,DETAILED_NETWORK_TYPE_HSPAP:114,DETAILED_NETWORK_TYPE_EHRPD:113,
DETAILED_NETWORK_TYPE_EVDO_B:112,DETAILED_NETWORK_TYPE_UMTS:111,DETAILED_NETWORK_TYPE_IDEN:110,DETAILED_NETWORK_TYPE_HSUPA:109,DETAILED_NETWORK_TYPE_HSPA:108,DETAILED_NETWORK_TYPE_HSDPA:107,DETAILED_NETWORK_TYPE_EVDO_A:106,DETAILED_NETWORK_TYPE_EVDO_0:105,DETAILED_NETWORK_TYPE_CDMA:104,DETAILED_NETWORK_TYPE_1_X_RTT:103,DETAILED_NETWORK_TYPE_GPRS:102,DETAILED_NETWORK_TYPE_EDGE:101,DETAILED_NETWORK_TYPE_UNKNOWN:0};Y[Y.DETAILED_NETWORK_TYPE_NR_NSA]="DETAILED_NETWORK_TYPE_NR_NSA";
Y[Y.DETAILED_NETWORK_TYPE_NR_SA]="DETAILED_NETWORK_TYPE_NR_SA";Y[Y.DETAILED_NETWORK_TYPE_INTERNAL_WIFI_IMPAIRED]="DETAILED_NETWORK_TYPE_INTERNAL_WIFI_IMPAIRED";Y[Y.DETAILED_NETWORK_TYPE_APP_WIFI_HOTSPOT]="DETAILED_NETWORK_TYPE_APP_WIFI_HOTSPOT";Y[Y.DETAILED_NETWORK_TYPE_DISCONNECTED]="DETAILED_NETWORK_TYPE_DISCONNECTED";Y[Y.DETAILED_NETWORK_TYPE_NON_MOBILE_UNKNOWN]="DETAILED_NETWORK_TYPE_NON_MOBILE_UNKNOWN";Y[Y.DETAILED_NETWORK_TYPE_MOBILE_UNKNOWN]="DETAILED_NETWORK_TYPE_MOBILE_UNKNOWN";
Y[Y.DETAILED_NETWORK_TYPE_WIMAX]="DETAILED_NETWORK_TYPE_WIMAX";Y[Y.DETAILED_NETWORK_TYPE_ETHERNET]="DETAILED_NETWORK_TYPE_ETHERNET";Y[Y.DETAILED_NETWORK_TYPE_BLUETOOTH]="DETAILED_NETWORK_TYPE_BLUETOOTH";Y[Y.DETAILED_NETWORK_TYPE_WIFI]="DETAILED_NETWORK_TYPE_WIFI";Y[Y.DETAILED_NETWORK_TYPE_LTE]="DETAILED_NETWORK_TYPE_LTE";Y[Y.DETAILED_NETWORK_TYPE_HSPAP]="DETAILED_NETWORK_TYPE_HSPAP";Y[Y.DETAILED_NETWORK_TYPE_EHRPD]="DETAILED_NETWORK_TYPE_EHRPD";Y[Y.DETAILED_NETWORK_TYPE_EVDO_B]="DETAILED_NETWORK_TYPE_EVDO_B";
Y[Y.DETAILED_NETWORK_TYPE_UMTS]="DETAILED_NETWORK_TYPE_UMTS";Y[Y.DETAILED_NETWORK_TYPE_IDEN]="DETAILED_NETWORK_TYPE_IDEN";Y[Y.DETAILED_NETWORK_TYPE_HSUPA]="DETAILED_NETWORK_TYPE_HSUPA";Y[Y.DETAILED_NETWORK_TYPE_HSPA]="DETAILED_NETWORK_TYPE_HSPA";Y[Y.DETAILED_NETWORK_TYPE_HSDPA]="DETAILED_NETWORK_TYPE_HSDPA";Y[Y.DETAILED_NETWORK_TYPE_EVDO_A]="DETAILED_NETWORK_TYPE_EVDO_A";Y[Y.DETAILED_NETWORK_TYPE_EVDO_0]="DETAILED_NETWORK_TYPE_EVDO_0";Y[Y.DETAILED_NETWORK_TYPE_CDMA]="DETAILED_NETWORK_TYPE_CDMA";
Y[Y.DETAILED_NETWORK_TYPE_1_X_RTT]="DETAILED_NETWORK_TYPE_1_X_RTT";Y[Y.DETAILED_NETWORK_TYPE_GPRS]="DETAILED_NETWORK_TYPE_GPRS";Y[Y.DETAILED_NETWORK_TYPE_EDGE]="DETAILED_NETWORK_TYPE_EDGE";Y[Y.DETAILED_NETWORK_TYPE_UNKNOWN]="DETAILED_NETWORK_TYPE_UNKNOWN";var Lr={LATENCY_PLAYER_RTSP:7,LATENCY_PLAYER_HTML5_INLINE:6,LATENCY_PLAYER_HTML5_FULLSCREEN:5,LATENCY_PLAYER_HTML5:4,LATENCY_PLAYER_FRAMEWORK:3,LATENCY_PLAYER_FLASH:2,LATENCY_PLAYER_EXO:1,LATENCY_PLAYER_UNKNOWN:0};Lr[Lr.LATENCY_PLAYER_RTSP]="LATENCY_PLAYER_RTSP";
Lr[Lr.LATENCY_PLAYER_HTML5_INLINE]="LATENCY_PLAYER_HTML5_INLINE";Lr[Lr.LATENCY_PLAYER_HTML5_FULLSCREEN]="LATENCY_PLAYER_HTML5_FULLSCREEN";Lr[Lr.LATENCY_PLAYER_HTML5]="LATENCY_PLAYER_HTML5";Lr[Lr.LATENCY_PLAYER_FRAMEWORK]="LATENCY_PLAYER_FRAMEWORK";Lr[Lr.LATENCY_PLAYER_FLASH]="LATENCY_PLAYER_FLASH";Lr[Lr.LATENCY_PLAYER_EXO]="LATENCY_PLAYER_EXO";Lr[Lr.LATENCY_PLAYER_UNKNOWN]="LATENCY_PLAYER_UNKNOWN";
var Mr={LATENCY_AD_BREAK_TYPE_POSTROLL:3,LATENCY_AD_BREAK_TYPE_MIDROLL:2,LATENCY_AD_BREAK_TYPE_PREROLL:1,LATENCY_AD_BREAK_TYPE_UNKNOWN:0};Mr[Mr.LATENCY_AD_BREAK_TYPE_POSTROLL]="LATENCY_AD_BREAK_TYPE_POSTROLL";Mr[Mr.LATENCY_AD_BREAK_TYPE_MIDROLL]="LATENCY_AD_BREAK_TYPE_MIDROLL";Mr[Mr.LATENCY_AD_BREAK_TYPE_PREROLL]="LATENCY_AD_BREAK_TYPE_PREROLL";Mr[Mr.LATENCY_AD_BREAK_TYPE_UNKNOWN]="LATENCY_AD_BREAK_TYPE_UNKNOWN";var Nr={LATENCY_ACTION_ERROR_STARTUP_TIMEOUT:1,LATENCY_ACTION_ERROR_UNSPECIFIED:0};
Nr[Nr.LATENCY_ACTION_ERROR_STARTUP_TIMEOUT]="LATENCY_ACTION_ERROR_STARTUP_TIMEOUT";Nr[Nr.LATENCY_ACTION_ERROR_UNSPECIFIED]="LATENCY_ACTION_ERROR_UNSPECIFIED";var Or={LIVE_STREAM_MODE_WINDOW:5,LIVE_STREAM_MODE_POST:4,LIVE_STREAM_MODE_LP:3,LIVE_STREAM_MODE_LIVE:2,LIVE_STREAM_MODE_DVR:1,LIVE_STREAM_MODE_UNKNOWN:0};Or[Or.LIVE_STREAM_MODE_WINDOW]="LIVE_STREAM_MODE_WINDOW";Or[Or.LIVE_STREAM_MODE_POST]="LIVE_STREAM_MODE_POST";Or[Or.LIVE_STREAM_MODE_LP]="LIVE_STREAM_MODE_LP";
Or[Or.LIVE_STREAM_MODE_LIVE]="LIVE_STREAM_MODE_LIVE";Or[Or.LIVE_STREAM_MODE_DVR]="LIVE_STREAM_MODE_DVR";Or[Or.LIVE_STREAM_MODE_UNKNOWN]="LIVE_STREAM_MODE_UNKNOWN";var Pr={VIDEO_STREAM_TYPE_VOD:3,VIDEO_STREAM_TYPE_DVR:2,VIDEO_STREAM_TYPE_LIVE:1,VIDEO_STREAM_TYPE_UNSPECIFIED:0};Pr[Pr.VIDEO_STREAM_TYPE_VOD]="VIDEO_STREAM_TYPE_VOD";Pr[Pr.VIDEO_STREAM_TYPE_DVR]="VIDEO_STREAM_TYPE_DVR";Pr[Pr.VIDEO_STREAM_TYPE_LIVE]="VIDEO_STREAM_TYPE_LIVE";Pr[Pr.VIDEO_STREAM_TYPE_UNSPECIFIED]="VIDEO_STREAM_TYPE_UNSPECIFIED";
var Qr={YT_IDB_TRANSACTION_TYPE_READ:2,YT_IDB_TRANSACTION_TYPE_WRITE:1,YT_IDB_TRANSACTION_TYPE_UNKNOWN:0};Qr[Qr.YT_IDB_TRANSACTION_TYPE_READ]="YT_IDB_TRANSACTION_TYPE_READ";Qr[Qr.YT_IDB_TRANSACTION_TYPE_WRITE]="YT_IDB_TRANSACTION_TYPE_WRITE";Qr[Qr.YT_IDB_TRANSACTION_TYPE_UNKNOWN]="YT_IDB_TRANSACTION_TYPE_UNKNOWN";var Rr={PLAYER_ROTATION_TYPE_PORTRAIT_TO_FULLSCREEN:2,PLAYER_ROTATION_TYPE_FULLSCREEN_TO_PORTRAIT:1,PLAYER_ROTATION_TYPE_UNKNOWN:0};Rr[Rr.PLAYER_ROTATION_TYPE_PORTRAIT_TO_FULLSCREEN]="PLAYER_ROTATION_TYPE_PORTRAIT_TO_FULLSCREEN";
Rr[Rr.PLAYER_ROTATION_TYPE_FULLSCREEN_TO_PORTRAIT]="PLAYER_ROTATION_TYPE_FULLSCREEN_TO_PORTRAIT";Rr[Rr.PLAYER_ROTATION_TYPE_UNKNOWN]="PLAYER_ROTATION_TYPE_UNKNOWN";var Sr="actionVisualElement spinnerInfo resourceInfo playerInfo commentInfo mdxInfo watchInfo thumbnailLoadInfo creatorInfo unpluggedInfo reelInfo subscriptionsFeedInfo requestIds mediaBrowserActionInfo musicLoadActionInfo shoppingInfo prefetchInfo accelerationSession webInfo tvInfo kabukiInfo mwebInfo musicInfo".split(" ");var Tr=y.ytLoggingLatencyUsageStats_||{};z("ytLoggingLatencyUsageStats_",Tr);function Ur(){this.i=0}
function Vr(){Ur.i||(Ur.i=new Ur);return Ur.i}
Ur.prototype.tick=function(a,b,c,d){Wr(this,"tick_"+a+"_"+b)||(c={timestamp:c,cttAuthInfo:d},M("web_csi_via_jspb")?(d=new Ch,C(d,1,a),C(d,2,b),a=new Fh,ud(a,5,Gh,d),xp(a,c)):ek("latencyActionTicked",{tickName:a,clientActionNonce:b},c))};
Ur.prototype.info=function(a,b,c){var d=Object.keys(a).join("");Wr(this,"info_"+d+"_"+b)||(a=Object.assign({},a),a.clientActionNonce=b,ek("latencyActionInfo",a,{cttAuthInfo:c}))};
Ur.prototype.jspbInfo=function(a,b,c){for(var d="",e=0;e<a.toJSON().length;e++)void 0!==a.toJSON()[e]&&(d=0===e?d.concat(""+e):d.concat("_"+e));Wr(this,"info_"+d+"_"+b)||(C(a,2,b),b={cttAuthInfo:c},c=new Fh,ud(c,7,Gh,a),xp(c,b))};
Ur.prototype.span=function(a,b,c){var d=Object.keys(a).join("");Wr(this,"span_"+d+"_"+b)||(a.clientActionNonce=b,ek("latencyActionSpan",a,{cttAuthInfo:c}))};
function Wr(a,b){Tr[b]=Tr[b]||{count:0};var c=Tr[b];c.count++;c.time=P();a.i||(a.i=Oj(function(){var d=P(),e;for(e in Tr)Tr[e]&&6E4<d-Tr[e].time&&delete Tr[e];a&&(a.i=0)},5E3));
return 5<c.count?(6===c.count&&1>1E5*Math.random()&&(c=new hk("CSI data exceeded logging limit with key",b.split("_")),0<=b.indexOf("plev")||Lp(c)),!0):!1}
;function Xr(){var a=["ol"];Br("").info.actionType="embed";a&&Sh("TIMING_AFT_KEYS",a);Sh("TIMING_ACTION","embed");Yr();a=tr();var b=vr();if("cold"===a.yt_lt||"cold"===b.loadType){var c=or(),d=ur();d=d.gelTicks?d.gelTicks:d.gelTicks={};for(var e in c)e in d||Z(e,c[e]);e={};c=!1;d=q(Object.keys(a));for(var f=d.next();!f.done;f=d.next())f=f.value,(f=Jr(f,a[f]))&&!yr(vr(),f)&&(cr(b,f),cr(e,f),c=!0);c&&Zr(e)}z("ytglobal.timingready_",!0);a=L("TIMING_ACTION");A("ytglobal.timingready_")&&a&&"_start"in or()&&
nr()&&xr()}
function $r(a,b,c,d){null!==b&&(tr(c)[a]=b,(a=Jr(a,b,c))&&Zr(a,c,d))}
function Zr(a,b,c){if(!M("web_csi_via_jspb")||(void 0===c?0:c))c=Br(b||""),cr(c.info,a),cr(vr(b),a),c=wr(b),b=sr(b).cttAuthInfo,Vr().info(a,c,b);else{c=new wh;var d=Object.keys(a);a=Object.values(a);for(var e=0;e<d.length;e++){var f=d[e];try{switch(f){case "actionType":yh(c,U[a[e]]);break;case "clientActionNonce":C(c,2,a[e]);break;case "clientScreenNonce":C(c,4,a[e]);break;case "loadType":C(c,3,a[e]);break;case "isPrewarmedLaunch":C(c,92,a[e]);break;case "isFirstInstall":C(c,55,a[e]);break;case "networkType":C(c,
5,Kr[a[e]]);break;case "connectionType":C(c,26,X[a[e]]);break;case "detailedConnectionType":C(c,27,Y[a[e]]);break;case "isVisible":C(c,6,a[e]);break;case "playerType":C(c,7,Lr[a[e]]);break;case "clientPlaybackNonce":C(c,8,a[e]);break;case "adClientPlaybackNonce":C(c,28,a[e]);break;case "previousCpn":C(c,77,a[e]);break;case "targetCpn":C(c,76,a[e]);break;case "isMonetized":C(c,9,a[e]);break;case "isPrerollAllowed":C(c,16,a[e]);break;case "isPrerollShown":C(c,17,a[e]);break;case "adType":C(c,12,a[e]);
break;case "adTypesAllowed":C(c,36,a[e]);break;case "adNetworks":C(c,37,a[e]);break;case "previousAction":C(c,13,U[a[e]]);break;case "isRedSubscriber":C(c,14,a[e]);break;case "serverTimeMs":C(c,15,a[e]);break;case "videoId":c.setVideoId(a[e]);break;case "adVideoId":C(c,20,a[e]);break;case "targetVideoId":C(c,78,a[e]);break;case "adBreakType":C(c,21,Mr[a[e]]);break;case "isNavigation":zh(c,a[e]);break;case "viewportHeight":C(c,29,a[e]);break;case "viewportWidth":C(c,30,a[e]);break;case "screenHeight":C(c,
84,a[e]);break;case "screenWidth":C(c,85,a[e]);break;case "browseId":C(c,31,a[e]);break;case "isCacheHit":C(c,32,a[e]);break;case "httpProtocol":C(c,33,a[e]);break;case "transportProtocol":C(c,34,a[e]);break;case "searchQuery":C(c,41,a[e]);break;case "isContinuation":C(c,42,a[e]);break;case "availableProcessors":C(c,43,a[e]);break;case "sdk":C(c,44,a[e]);break;case "isLocalStream":C(c,45,a[e]);break;case "navigationRequestedSameUrl":C(c,64,a[e]);break;case "shellStartupDurationMs":C(c,70,a[e]);break;
case "appInstallDataAgeMs":C(c,73,a[e]);break;case "latencyActionError":C(c,71,Nr[a[e]]);break;case "actionStep":C(c,79,a[e]);break;case "jsHeapSizeLimit":C(c,80,a[e]);break;case "totalJsHeapSize":C(c,81,a[e]);break;case "usedJsHeapSize":C(c,82,a[e]);break;case "sourceVideoDurationMs":C(c,90,a[e]);break;case "videoOutputFrames":C(c,93,a[e]);break;case "adPrebufferedTimeSecs":C(c,39,a[e]);break;case "isLivestream":C(c,47,a[e]);break;case "liveStreamMode":C(c,91,Or[a[e]]);break;case "adCpn2":C(c,48,
a[e]);break;case "adDaiDriftMillis":C(c,49,a[e]);break;case "videoStreamType":C(c,53,Pr[a[e]]);break;case "playbackRequiresTap":C(c,56,a[e]);break;case "performanceNavigationTiming":C(c,67,a[e]);break;case "transactionType":C(c,74,Qr[a[e]]);break;case "playerRotationType":C(c,101,Rr[a[e]]);break;case "allowedPreroll":C(c,10,a[e]);break;case "shownPreroll":C(c,11,a[e]);break;case "getHomeRequestId":C(c,57,a[e]);break;case "getSearchRequestId":C(c,60,a[e]);break;case "getPlayerRequestId":C(c,61,a[e]);
break;case "getWatchNextRequestId":C(c,62,a[e]);break;case "getBrowseRequestId":C(c,63,a[e]);break;case "getLibraryRequestId":C(c,66,a[e]);break;default:Sr.includes(f)&&ai(new hk("Codegen laipb translator asked to translate message field",""+f))}}catch(g){ai(Error("Codegen laipb translator failed to set "+f))}}as(c,b)}}
function as(a,b){var c=ur(b);c.jspbInfos||(c.jspbInfos=[]);c.jspbInfos.push(a);Br(b||"").jspbInfo.push(a);c=wr(b);b=sr(b).cttAuthInfo;Vr().jspbInfo(a,c,b)}
function Z(a,b,c){if(!b&&"_"!==a[0]){var d=a;Q.mark&&(0==d.lastIndexOf("mark_",0)||(d="mark_"+d),c&&(d+=" ("+c+")"),Q.mark(d))}Br(c||"").tick[a]=b||P();d=ur(c);d.gelTicks&&(d.gelTicks[a]=!0);d=or(c);var e=b||P();d[a]=e;e=wr(c);var f=sr(c).cttAuthInfo;if("_start"===a){var g=Vr();Wr(g,"baseline_"+e)||(b={timestamp:b,cttAuthInfo:f},M("web_csi_via_jspb")?(f=new uh,C(f,1,e),e=new Fh,ud(e,6,Gh,f),xp(e,b)):ek("latencyActionBaselined",{clientActionNonce:e},b))}else Vr().tick(a,e,b,f);xr(c);return d[a]}
function bs(){var a=wr();requestAnimationFrame(function(){setTimeout(function(){a===wr()&&Z("ol",void 0,void 0)},0)})}
function cs(){var a=document;if("visibilityState"in a)a=a.visibilityState;else{var b=pn+"VisibilityState";a=b in a?a[b]:void 0}switch(a){case "hidden":return 0;case "visible":return 1;case "prerender":return 2;case "unloaded":return 3;default:return-1}}
function Yr(){function a(f){var g=pr(),h=rr();h&&(Z("srt",g.responseStart),1!==f.prerender&&Z("_start",h,void 0));f=zr();0<f&&Z("fpt",f);f=pr();f.isPerformanceNavigationTiming&&Zr({performanceNavigationTiming:!0});Z("nreqs",f.requestStart,void 0);Z("nress",f.responseStart,void 0);Z("nrese",f.responseEnd,void 0);0<f.redirectEnd-f.redirectStart&&(Z("nrs",f.redirectStart,void 0),Z("nre",f.redirectEnd,void 0));0<f.domainLookupEnd-f.domainLookupStart&&(Z("ndnss",f.domainLookupStart,void 0),Z("ndnse",f.domainLookupEnd,
void 0));0<f.connectEnd-f.connectStart&&(Z("ntcps",f.connectStart,void 0),Z("ntcpe",f.connectEnd,void 0));f.secureConnectionStart>=rr()&&0<f.connectEnd-f.secureConnectionStart&&(Z("nstcps",f.secureConnectionStart,void 0),Z("ntcpe",f.connectEnd,void 0));Q&&"getEntriesByType"in Q&&ds()}
var b=L("TIMING_INFO",{});if(M("web_csi_via_jspb")){b=es(b);as(b);b=yh(zh(new wh,!0),U[Ir(L("TIMING_ACTION"))]);var c=L("PREVIOUS_ACTION");c&&C(b,13,U[Ir(c)]);(c=L("CLIENT_PROTOCOL"))&&C(b,33,c);(c=L("CLIENT_TRANSPORT"))&&C(b,34,c);(c=cq())&&"UNDEFINED_CSN"!==c&&C(b,4,c);c=cs();1!==c&&-1!==c||C(b,6,!0);c=tr();C(b,3,"cold");a(c);c=fs();if(0<c.length){c=q(c);for(var d=c.next();!d.done;d=c.next()){d=d.value;var e=new vh;C(e,1,d);vd(b,83,vh,e)}}as(b)}else{for(c in b)b.hasOwnProperty(c)&&$r(c,b[c]);b=
{isNavigation:!0,actionType:Ir(L("TIMING_ACTION"))};if(c=L("PREVIOUS_ACTION"))b.previousAction=Ir(c);if(c=L("CLIENT_PROTOCOL"))b.httpProtocol=c;if(c=L("CLIENT_TRANSPORT"))b.transportProtocol=c;(c=cq())&&"UNDEFINED_CSN"!==c&&(b.clientScreenNonce=c);c=cs();if(1===c||-1===c)b.isVisible=!0;c=tr();b.loadType="cold";a(c);c=fs();if(0<c.length)for(b.resourceInfo=[],c=q(c),d=c.next();!d.done;d=c.next())b.resourceInfo.push({resourceCache:d.value});Zr(b)}}
function es(a){var b=new wh;a=q(Object.entries(a));for(var c=a.next();!c.done;c=a.next()){var d=q(c.value);c=d.next().value;d=d.next().value;switch(c){case "GetBrowse_rid":var e=new Bh;C(e,1,c);C(e,2,String(d));Ah(b,e);break;case "GetGuide_rid":e=new Bh;C(e,1,c);C(e,2,String(d));Ah(b,e);break;case "GetHome_rid":e=new Bh;C(e,1,c);C(e,2,String(d));Ah(b,e);break;case "GetPlayer_rid":e=new Bh;C(e,1,c);C(e,2,String(d));Ah(b,e);break;case "GetSearch_rid":e=new Bh;C(e,1,c);C(e,2,String(d));Ah(b,e);break;
case "GetSettings_rid":e=new Bh;C(e,1,c);C(e,2,String(d));Ah(b,e);break;case "GetTrending_rid":e=new Bh;C(e,1,c);C(e,2,String(d));Ah(b,e);break;case "GetWatchNext_rid":e=new Bh;C(e,1,c);C(e,2,String(d));Ah(b,e);break;case "yt_red":C(b,14,!!d);break;case "yt_ad":C(b,9,!!d)}}return b}
function gs(a,b){a=document.querySelector(a);if(!a)return!1;var c="",d=a.nodeName;"SCRIPT"===d?(c=a.src,c||(c=a.getAttribute("data-timing-href"))&&(c=window.location.protocol+c)):"LINK"===d&&(c=a.href);Wb()&&a.setAttribute("nonce",Wb());return c?(a=Q.getEntriesByName(c))&&a[0]&&(a=a[0],c=rr(),Z("rsf_"+b,c+Math.round(a.fetchStart)),Z("rse_"+b,c+Math.round(a.responseEnd)),void 0!==a.transferSize&&0===a.transferSize)?!0:!1:!1}
function fs(){var a=[];if(document.querySelector&&Q&&Q.getEntriesByName)for(var b in mr)if(mr.hasOwnProperty(b)){var c=mr[b];gs(b,c)&&a.push(c)}return a}
function ds(){var a=window.location.protocol,b=Q.getEntriesByType("resource");b=eb(b,function(c){return 0===c.name.indexOf(a+"//fonts.gstatic.com/s/")});
(b=gb(b,function(c,d){return d.duration>c.duration?d:c},{duration:0}))&&0<b.startTime&&0<b.responseEnd&&(Z("wffs",qr(b.startTime)),Z("wffe",qr(b.responseEnd)))}
var hs=window;hs.ytcsi&&(hs.ytcsi.info=$r,hs.ytcsi.tick=Z);var is="tokens consistency mss client_location entities response_received_commands store".split(" ");function js(a,b,c,d){this.s=a;this.J=b;this.m=c;this.l=d;this.j=void 0;this.i=new Map;a.Aa||(a.Aa={});a.Aa=Object.assign({},br,a.Aa)}
function ks(a,b,c,d){if(void 0!==js.i){if(d=js.i,a=[a!==d.s,b!==d.J,c!==d.m,!1,!1,void 0!==d.j],a.some(function(e){return e}))throw new hk("InnerTubeTransportService is already initialized",a);
}else js.i=new js(a,b,c,d)}
function ls(a){var b={signalServiceEndpoint:{signal:"GET_DATASYNC_IDS"}};var c=void 0===c?Lq:c;var d=Uq(b,a.s);if(!d)return fg(new hk("Error: No request builder found for command.",b));var e=d.s(b,void 0,c);return e?new ag(function(f){var g,h,k;return w(function(m){if(1==m.i){h="cors"===(null==(g=e.ra)?void 0:g.mode)?"cors":void 0;if(a.m.Cc){var p=e.config,u;p=null==p?void 0:null==(u=p.Ha)?void 0:u.sessionIndex;u=Cq({sessionIndex:p});k=Object.assign({},ms(h),u);return m.u(2)}return t(m,ns(e.config,
h),3)}2!=m.i&&(k=m.j);f(os(a,e,k));m.i=0})}):fg(new hk("Error: Failed to build request for command.",b))}
function os(a,b,c){var d,e,f,g,h,k,m,p,u,x,v,E,G,K,N,O,S,ka,V;return w(function(W){switch(W.i){case 1:W.u(2);break;case 3:if((d=W.j)&&!d.isExpired())return W.return(Promise.resolve(d.i()));case 2:if(null==(e=b)?0:null==(f=e.Z)?0:f.context)for(g=q([]),h=g.next();!h.done;h=g.next())k=h.value,k.yp(b.Z.context);if(null==(m=a.j)?0:m.Dp(b.input,b.Z))return W.return(a.j.vp(b.input,b.Z));(x=null==(u=b.config)?void 0:u.Ap)&&a.i.has(x)&&M("web_memoize_inflight_requests")?p=a.i.get(x):(v=JSON.stringify(b.Z),
b.ra=Object.assign({},b.ra,{headers:c}),E=Object.assign({},b.ra),"POST"===b.ra.method&&(E=Object.assign({},E,{body:v})),(null==(G=b.config)?0:G.nc)&&Z(b.config.nc),K=function(){return a.J.fetch(b.input,E,b.config)},p=K(),x&&a.i.set(x,p));
return t(W,p,4);case 4:N=W.j;x&&a.i.has(x)&&a.i.delete(x);(null==(O=b.config)?0:O.oc)&&Z(b.config.oc);if(N||null==(S=a.j)||!S.qp(b.input,b.Z)){W.u(5);break}return t(W,a.j.up(b.input,b.Z),6);case 6:N=W.j;case 5:if(N&&a.l)for(ka=q(is),h=ka.next();!h.done;h=ka.next())V=h.value,a.l[V]&&a.l[V].handleResponse(N,b);return W.return(N)}})}
function ns(a,b){var c,d,e,f;return w(function(g){if(1==g.i){e=null==(c=a)?void 0:null==(d=c.Ha)?void 0:d.sessionIndex;var h=Cq({sessionIndex:e});if(!(h instanceof ag)){var k=new ag(ab);bg(k,2,h);h=k}return t(g,h,2)}f=g.j;return g.return(Promise.resolve(Object.assign({},ms(b),f)))})}
function ms(a){var b={"Content-Type":"application/json"};M("enable_web_eom_visitor_data")&&L("EOM_VISITOR_DATA")?b["X-Goog-EOM-Visitor-Id"]=L("EOM_VISITOR_DATA"):L("VISITOR_DATA")&&(b["X-Goog-Visitor-Id"]=L("VISITOR_DATA"));M("track_webfe_innertube_auth_mismatch")&&(b["X-Youtube-Bootstrap-Logged-In"]=L("LOGGED_IN",!1));"cors"!==a&&((a=L("INNERTUBE_CONTEXT_CLIENT_NAME"))&&(b["X-Youtube-Client-Name"]=a),(a=L("INNERTUBE_CONTEXT_CLIENT_VERSION"))&&(b["X-Youtube-Client-Version"]=a),(a=L("CHROME_CONNECTED_HEADER"))&&
(b["X-Youtube-Chrome-Connected"]=a),(a=L("DOMAIN_ADMIN_STATE"))&&(b["X-Youtube-Domain-Admin-State"]=a));return b}
;var ps=["share/get_web_player_share_panel"],qs=["feedback"],rs=["notification/modify_channel_preference"],ss=["browse/edit_playlist"],ts=["subscription/subscribe"],us=["subscription/unsubscribe"];function vs(){}
r(vs,Zq);vs.prototype.l=function(){return ts};
vs.prototype.i=function(a){return a.subscribeEndpoint};
vs.prototype.j=function(a,b,c){c=void 0===c?{}:c;b.channelIds&&(a.channelIds=b.channelIds);b.siloName&&(a.siloName=b.siloName);b.params&&(a.params=b.params);c.botguardResponse&&(a.botguardResponse=c.botguardResponse);c.feature&&(a.clientFeature=c.feature)};
da.Object.defineProperties(vs.prototype,{m:{configurable:!0,enumerable:!0,get:function(){return!0}}});function ws(){}
r(ws,Zq);ws.prototype.l=function(){return us};
ws.prototype.i=function(a){return a.unsubscribeEndpoint};
ws.prototype.j=function(a,b){b.channelIds&&(a.channelIds=b.channelIds);b.siloName&&(a.siloName=b.siloName);b.params&&(a.params=b.params)};
da.Object.defineProperties(ws.prototype,{m:{configurable:!0,enumerable:!0,get:function(){return!0}}});function xs(){}
r(xs,Zq);xs.prototype.l=function(){return qs};
xs.prototype.i=function(a){return a.feedbackEndpoint};
xs.prototype.j=function(a,b,c){a.feedbackTokens=[];b.feedbackToken&&a.feedbackTokens.push(b.feedbackToken);if(b=b.cpn||c.cpn)a.feedbackContext={cpn:b};a.isFeedbackTokenUnencrypted=!!c.is_feedback_token_unencrypted;a.shouldMerge=!1;c.extra_feedback_tokens&&(a.shouldMerge=!0,a.feedbackTokens=a.feedbackTokens.concat(c.extra_feedback_tokens))};
da.Object.defineProperties(xs.prototype,{m:{configurable:!0,enumerable:!0,get:function(){return!0}}});function ys(){}
r(ys,Zq);ys.prototype.l=function(){return rs};
ys.prototype.i=function(a){return a.modifyChannelNotificationPreferenceEndpoint};
ys.prototype.j=function(a,b){b.params&&(a.params=b.params);b.secondaryParams&&(a.secondaryParams=b.secondaryParams)};function zs(){}
r(zs,Zq);zs.prototype.l=function(){return ss};
zs.prototype.i=function(a){return a.playlistEditEndpoint};
zs.prototype.j=function(a,b){b.actions&&(a.actions=b.actions);b.params&&(a.params=b.params);b.playlistId&&(a.playlistId=b.playlistId)};function As(){}
r(As,Zq);As.prototype.l=function(){return ps};
As.prototype.i=function(a){return a.webPlayerShareEntityServiceEndpoint};
As.prototype.j=function(a,b,c){c=void 0===c?{}:c;b.serializedShareEntity&&(a.serializedSharedEntity=b.serializedShareEntity);c.includeListId&&(a.includeListId=!0)};var Gq=new Eq("NETWORK_SLI_TOKEN");function Bs(a){this.i=a}
Bs.prototype.fetch=function(a,b){var c=this,d,e;return w(function(f){c.i&&(d=$b(ac(5,jc(a)))||"/UNKNOWN_PATH",c.i.start(d));e=new window.Request(a,b);return M("web_fetch_promise_cleanup_killswitch")?f.return(Promise.resolve(fetch(e).then(function(g){return c.handleResponse(g)}).catch(function(g){Lp(g)}))):f.return(fetch(e).then(function(g){return c.handleResponse(g)}).catch(function(g){Lp(g)}))})};
Bs.prototype.handleResponse=function(a){var b=a.text().then(function(c){return JSON.parse(c.replace(")]}'",""))});
a.redirected||a.ok?this.i&&this.i.success():(this.i&&this.i.failure(),b=b.then(function(c){Lp(new hk("Error: API fetch failed",a.status,a.url,c));return Object.assign({},c,{errorMetadata:{status:a.status}})}));
return b};
Bs[Dq]=[new Fq];var Cs=new Eq("NETWORK_MANAGER_TOKEN");var Ds;function Es(a){Nl.call(this,1,arguments);this.csn=a}
r(Es,Nl);var Wl=new Ol("screen-created",Es),Fs=[],Hs=Gs,Is=0;function Js(a,b,c,d,e,f,g){function h(){Lp(new hk("newScreen() parent element does not have a VE - rootVe",b))}
var k=Hs();f=new Wp({veType:b,youtubeData:f,jspbYoutubeData:void 0});e={cttAuthInfo:e,V:k};if(M("il_via_jspb")){var m=new kh;m.P(k);lh(m,f.getAsJspb());c&&c.visualElement?(f=new mh,c.clientScreenNonce&&C(f,2,c.clientScreenNonce),nh(f,c.visualElement.getAsJspb()),g&&C(f,4,Hh[g]),D(m,5,f)):c&&h();d&&C(m,3,d);Bp(m,e,a)}else f={csn:k,pageVe:f.getAsJson()},c&&c.visualElement?(f.implicitGesture={parentCsn:c.clientScreenNonce,gesturedVe:c.visualElement.getAsJson()},g&&(f.implicitGesture.gestureType=g)):
c&&h(),d&&(f.cloneCsn=d),a?gp("screenCreated",f,a,e):ek("screenCreated",f,e);Tl(Wl,new Es(k));return k}
function Ks(a,b,c,d){var e=d.filter(function(k){k.csn!==b?(k.csn=b,k=!0):k=!1;return k}),f={cttAuthInfo:eq(b),
V:b};d=q(d);for(var g=d.next();!g.done;g=d.next())g=g.value.getAsJson(),(nb(g)||!g.trackingParams&&!g.veType)&&Lp(Error("Child VE logged with no data"));if(M("il_via_jspb")){var h=new oh;h.P(b);qh(h,c.getAsJspb());fb(e,function(k){k=k.getAsJspb();vd(h,3,ih,k)});
"UNDEFINED_CSN"==b?Ls("visualElementAttached",h,f):Cp(h,f,a)}else c={csn:b,parentVe:c.getAsJson(),childVes:fb(e,function(k){return k.getAsJson()})},"UNDEFINED_CSN"==b?Ls("visualElementAttached",c,f):a?gp("visualElementAttached",c,a,f):ek("visualElementAttached",c,f)}
function Gs(){for(var a=Math.random()+"",b=[],c=0,d=0;d<a.length;d++){var e=a.charCodeAt(d);255<e&&(b[c++]=e&255,e>>=8);b[c++]=e}return Lc(b,3)}
function Ls(a,b,c){Fs.push({payloadName:a,payload:b,options:c});Is||(Is=Xl())}
function Yl(a){if(Fs){for(var b=q(Fs),c=b.next();!c.done;c=b.next()){var d=c.value;if(d.payload)if(M("il_via_jspb"))switch(d.payload.P(a.csn),d.payloadName){case "screenCreated":Bp(d.payload,d.options);break;case "visualElementAttached":Cp(d.payload,d.options);break;case "visualElementShown":c=d.payload;d=d.options;var e=new Fh;ud(e,72,Gh,c);xp(e,d);break;case "visualElementHidden":yp(d.payload,d.options);break;case "visualElementGestured":zp(d.payload,d.options);break;case "visualElementStateChanged":Ap(d.payload,
d.options);break;default:Lp(new hk("flushQueue unable to map payloadName to JSPB setter"))}else d.payload.csn=a.csn,gp(d.payloadName,d.payload,null,d.options)}Fs.length=0}Is=0}
;function Ms(){this.j=new Set;this.i=new Set;this.l=new Map}
Ms.prototype.clear=function(){this.j.clear();this.i.clear();this.l.clear()};
La(Ms);function Ns(){this.s=[];this.F=[];this.i=[];this.m=[];this.o=[];this.j=new Set;this.v=new Map}
function Os(a,b,c){c=void 0===c?0:c;b.then(function(d){a.j.has(c)&&a.l&&a.l();var e=cq(c),f=aq(c);if(e&&f){var g;(null==d?0:null==(g=d.response)?0:g.trackingParams)&&Ks(a.client,e,f,[Xp(d.response.trackingParams)]);var h;(null==d?0:null==(h=d.playerResponse)?0:h.trackingParams)&&Ks(a.client,e,f,[Xp(d.playerResponse.trackingParams)])}})}
function Ps(a,b,c,d){d=void 0===d?0:d;if(a.j.has(d))a.s.push([b,c]);else{var e=cq(d);c=c||aq(d);e&&c&&Ks(a.client,e,c,[b])}}
Ns.prototype.clickCommand=function(a,b,c){var d=a.clickTrackingParams;c=void 0===c?0:c;if(d)if(c=cq(void 0===c?0:c)){a=this.client;var e=Xp(d);var f="INTERACTION_LOGGING_GESTURE_TYPE_GENERIC_CLICK";d={cttAuthInfo:eq(c),V:c};if(M("il_via_jspb")){var g=new rh;g.P(c);e=e.getAsJspb();D(g,2,e);C(g,4,Hh[f]);b&&D(g,3);"UNDEFINED_CSN"==c?Ls("visualElementGestured",g,d):zp(g,d,a)}else f={csn:c,ve:e.getAsJson(),gestureType:f},b&&(f.clientData=b),"UNDEFINED_CSN"==c?Ls("visualElementGestured",f,d):a?gp("visualElementGestured",
f,a,d):ek("visualElementGestured",f,d);b=!0}else b=!1;else b=!1;return b};
function Qs(a,b,c){c=void 0===c?{}:c;a.j.add(c.layer||0);a.l=function(){Rs(a,b,c);var f=aq(c.layer);if(f){for(var g=q(a.s),h=g.next();!h.done;h=g.next())h=h.value,Ps(a,h[0],h[1]||f,c.layer);f=q(a.F);for(g=f.next();!g.done;g=f.next()){var k=g.value;g=void 0;g=void 0===g?0:g;h=cq(g);var m=k[0]||aq(g);if(h&&m){g=a.client;var p=k[1];k={cttAuthInfo:eq(h),V:h};M("il_via_jspb")?(p=new th,p.P(h),m=m.getAsJspb(),D(p,2,m),"UNDEFINED_CSN"==h?Ls("visualElementStateChanged",p,k):Ap(p,k,g)):(m={csn:h,ve:m.getAsJson(),
clientData:p},"UNDEFINED_CSN"==h?Ls("visualElementStateChanged",m,k):g?gp("visualElementStateChanged",m,g,k):ek("visualElementStateChanged",m,k))}}}};
cq(c.layer)||a.l();if(c.ub)for(var d=q(c.ub),e=d.next();!e.done;e=d.next())Os(a,e.value,c.layer);else Kp(Error("Delayed screen needs a data promise."))}
function Rs(a,b,c){c=void 0===c?{}:c;c.layer||(c.layer=0);var d=void 0!==c.ic?c.ic:c.layer;var e=cq(d);d=aq(d);var f;d&&(void 0!==c.parentCsn?f={clientScreenNonce:c.parentCsn,visualElement:d}:e&&"UNDEFINED_CSN"!==e&&(f={clientScreenNonce:e,visualElement:d}));var g,h=L("EVENT_ID");"UNDEFINED_CSN"===e&&h&&(g={servletData:{serializedServletEventId:h}});try{var k=Js(a.client,b,f,c.tb,c.cttAuthInfo,g,c.tp)}catch(m){Np(m,{Bp:b,rootVe:d,parentVisualElement:void 0,rp:e,xp:f,tb:c.tb});Kp(m);return}fq(k,b,
c.layer,c.cttAuthInfo);if(b=e&&"UNDEFINED_CSN"!==e&&d){a:{b=q(Object.values(Vp));for(f=b.next();!f.done;f=b.next())if(cq(f.value)===e){b=!0;break a}b=!1}b=!b}b&&(b=a.client,g=!0,h=(g=void 0===g?!1:g)?16:8,f={cttAuthInfo:eq(e),V:e,wb:g},M("il_via_jspb")?(h=new sh,h.P(e),d=d.getAsJspb(),D(h,2,d),C(h,4,g?16:8),"UNDEFINED_CSN"==e?Ls("visualElementHidden",h,f):yp(h,f,b)):(d={csn:e,ve:d.getAsJson(),eventType:h},"UNDEFINED_CSN"==e?Ls("visualElementHidden",d,f):b?gp("visualElementHidden",d,b,f):ek("visualElementHidden",
d,f)));a.i[a.i.length-1]&&!a.i[a.i.length-1].csn&&(a.i[a.i.length-1].csn=k||"");Zr({clientScreenNonce:k});Ms.getInstance().clear();d=aq(c.layer);e&&"UNDEFINED_CSN"!==e&&d&&(M("web_mark_root_visible")||M("music_web_mark_root_visible"))&&(e={cttAuthInfo:eq(k),V:k},M("il_via_jspb")?(b=new sh,b.P(k),f=d.getAsJspb(),D(b,2,f),C(b,4,1),"UNDEFINED_CSN"==k?Ls("visualElementShown",b,e):(k=new Fh,ud(k,72,Gh,b),xp(k,e))):(b={csn:k,ve:d.getAsJson(),eventType:1},"UNDEFINED_CSN"==k?Ls("visualElementShown",b,e):
ek("visualElementShown",b,e)));a.j.delete(c.layer||0);a.l=void 0;e=q(a.v);for(k=e.next();!k.done;k=e.next())b=q(k.value),k=b.next().value,b=b.next().value,b.has(c.layer)&&d&&Ps(a,k,d,c.layer);for(c=0;c<a.m.length;c++){e=a.m[c];try{e()}catch(m){Kp(m)}}for(c=a.m.length=0;c<a.o.length;c++){e=a.o[c];try{e()}catch(m){Kp(m)}}}
;function Ss(){var a,b;return w(function(c){if(1==c.i)return a=js.i,a?t(c,ls(a),2):(Lp(Error("InnertubeTransportService unavailable in fetchDatasyncIds")),c.return(void 0));if(b=c.j)return b.errorMetadata?(Lp(Error("Datasync IDs fetch responded with "+b.errorMetadata.status+": "+b.error)),c.return(void 0)):c.return(b.sp);Lp(Error("Network request to get Datasync IDs failed."));return c.return(void 0)})}
;var Ts=y.caches,Us;function Vs(a){var b=a.indexOf(":");return-1===b?{Fb:a}:{Fb:a.substring(0,b),datasyncId:a.substring(b+1)}}
function Ws(){return w(function(a){if(void 0!==Us)return a.return(Us);Us=new Promise(function(b){var c;return w(function(d){switch(d.i){case 1:return ua(d,2),t(d,Ts.open("test-only"),4);case 4:return t(d,Ts.delete("test-only"),5);case 5:xa(d,3);break;case 2:if(c=ya(d),c instanceof Error&&"SecurityError"===c.name)return b(!1),d.return();case 3:b("caches"in window),d.i=0}})});
return a.return(Us)})}
function Xs(a){var b,c,d,e,f,g,h;w(function(k){if(1==k.i)return t(k,Ws(),2);if(3!=k.i){if(!k.j)return k.return(!1);b=[];return t(k,Ts.keys(),3)}c=k.j;d=q(c);for(e=d.next();!e.done;e=d.next())f=e.value,g=Vs(f),h=g.datasyncId,!h||a.includes(h)||b.push(Ts.delete(f));return k.return(Promise.all(b).then(function(m){return m.some(function(p){return p})}))})}
function Ys(){var a,b,c,d,e,f,g;return w(function(h){if(1==h.i)return t(h,Ws(),2);if(3!=h.i){if(!h.j)return h.return(!1);a=jk("cache contains other");return t(h,Ts.keys(),3)}b=h.j;c=q(b);for(d=c.next();!d.done;d=c.next())if(e=d.value,f=Vs(e),(g=f.datasyncId)&&g!==a)return h.return(!0);return h.return(!1)})}
;function Zs(){try{return!!self.localStorage}catch(a){return!1}}
;function $s(a){a=a.match(/(.*)::.*::.*/);if(null!==a)return a[1]}
function at(a){if(Zs()){var b=Object.keys(window.localStorage);b=q(b);for(var c=b.next();!c.done;c=b.next()){c=c.value;var d=$s(c);void 0===d||a.includes(d)||self.localStorage.removeItem(c)}}}
function bt(){if(!Zs())return!1;var a=jk(),b=Object.keys(window.localStorage);b=q(b);for(var c=b.next();!c.done;c=b.next())if(c=$s(c.value),void 0!==c&&c!==a)return!0;return!1}
;function ct(){Ss().then(function(a){a&&(ul(a),Xs(a),at(a))})}
function dt(){var a=new Im;gf.M(function(){var b,c,d,e;return w(function(f){switch(f.i){case 1:if(M("ytidb_clear_optimizations_killswitch")){f.u(2);break}b=jk("clear");if(b.startsWith("V")){var g=[b];ul(g);Xs(g);at(g);return f.return()}c=bt();return t(f,Ys(),3);case 3:return d=f.j,t(f,vl(),4);case 4:if(e=f.j,!c&&!d&&!e)return f.return();case 2:a.H()?ct():a.m.add("publicytnetworkstatus-online",ct,!0,void 0,void 0),f.i=0}})})}
;function et(a){a&&(a.dataset?a.dataset[ft("loaded")]="true":a.setAttribute("data-loaded","true"))}
function gt(a,b){return a?a.dataset?a.dataset[ft(b)]:a.getAttribute("data-"+b):null}
var ht={};function ft(a){return ht[a]||(ht[a]=String(a).replace(/\-([a-z])/g,function(b,c){return c.toUpperCase()}))}
;var jt=/\.vflset|-vfl[a-zA-Z0-9_+=-]+/,kt=/-[a-zA-Z]{2,3}_[a-zA-Z]{2,3}(?=(\/|$))/;function lt(a,b,c){c=void 0===c?null:c;if(window.spf&&spf.script){c="";if(a){var d=a.indexOf("jsbin/"),e=a.lastIndexOf(".js"),f=d+6;-1<d&&-1<e&&e>f&&(c=a.substring(f,e),c=c.replace(jt,""),c=c.replace(kt,""),c=c.replace("debug-",""),c=c.replace("tracing-",""))}spf.script.load(a,c,b)}else mt(a,b,c)}
function mt(a,b,c){c=void 0===c?null:c;var d=nt(a),e=document.getElementById(d),f=e&&gt(e,"loaded"),g=e&&!f;f?b&&b():(b&&(f=Jn(d,b),b=""+Qa(b),ot[b]=f),g||(e=pt(a,d,function(){gt(e,"loaded")||(et(e),Mn(d),ui(Wa(Nn,d),0))},c)))}
function pt(a,b,c,d){d=void 0===d?null:d;var e=Rd("SCRIPT");e.id=b;e.onload=function(){c&&setTimeout(c,0)};
e.onreadystatechange=function(){switch(e.readyState){case "loaded":case "complete":e.onload()}};
d&&e.setAttribute("nonce",d);Nd(e,Hb(a));a=document.getElementsByTagName("head")[0]||document.body;a.insertBefore(e,a.firstChild);return e}
function qt(a){a=nt(a);var b=document.getElementById(a);b&&(Nn(a),b.parentNode.removeChild(b))}
function rt(a,b){a&&b&&(a=""+Qa(b),(a=ot[a])&&Ln(a))}
function nt(a){var b=document.createElement("a");Tb(b,a);a=b.href.replace(/^[a-zA-Z]+:\/\//,"//");return"js-"+Yb(a)}
var ot={};var st=[],tt=!1;function ut(){if(!M("disable_biscotti_fetch_for_ad_blocker_detection")&&!M("disable_biscotti_fetch_entirely_for_all_web_clients")&&rq()){var a=L("PLAYER_VARS",{});if(!("1"==pb(a)||M("embeds_web_disable_ads_for_pfl")&&sq(a))){var b=function(){tt=!0;"google_ad_status"in window?Sh("DCLKSTAT",1):Sh("DCLKSTAT",2)};
try{lt("//static.doubleclick.net/instream/ad_status.js",b)}catch(c){}st.push(gf.M(function(){if(!(tt||"google_ad_status"in window)){try{rt("//static.doubleclick.net/instream/ad_status.js",b)}catch(c){}tt=!0;Sh("DCLKSTAT",3)}},5E3))}}}
function xt(){var a=Number(L("DCLKSTAT",0));return isNaN(a)?0:a}
;function zt(){this.state=1;this.i=null}
zt.prototype.initialize=function(a,b,c){if(a.program){var d,e=null!=(d=a.interpreterScript)?d:null,f;d=null!=(f=a.interpreterUrl)?f:null;a.interpreterSafeScript&&(e=a.interpreterSafeScript,Bb("From proto message. b/166824318"),e=e.privateDoNotAccessOrElseSafeScriptWrappedValue||"",e=(f=yb())?f.createScript(e):e,e=(new Db(e)).toString());a.interpreterSafeUrl&&(d=a.interpreterSafeUrl,Bb("From proto message. b/166824318"),d=Hb(d.privateDoNotAccessOrElseTrustedResourceUrlWrappedValue||"").toString());
At(this,e,d,a.program,b,c)}else Lp(Error("Cannot initialize botguard without program"))};
function At(a,b,c,d,e,f){var g=void 0===g?"trayride":g;c?(a.state=2,lt(c,function(){window[g]?Bt(a,d,g,e):(a.state=3,qt(c),Lp(new hk("Unable to load Botguard","from "+c)))},f)):b?(f=Rd("SCRIPT"),f.textContent=b,f.nonce=Wb(),document.head.appendChild(f),document.head.removeChild(f),window[g]?Bt(a,d,g,e):(a.state=4,Lp(new hk("Unable to load Botguard from JS")))):Lp(new hk("Unable to load VM; no url or JS provided"))}
zt.prototype.isInitialized=function(){return!!this.i};
function Bt(a,b,c,d){a.state=5;try{var e=new Gd({program:b,globalName:c});e.zc.then(function(){a.state=6;d&&d(b)});
Ct(a,e)}catch(f){a.state=7,f instanceof Error&&Lp(f)}}
zt.prototype.invoke=function(a){a=void 0===a?{}:a;if(this.i){var b=this.i;a={sb:a};if(b.j)throw Error("Already disposed");b=b.m([a.sb,a.Bc])}else b=null;return b};
zt.prototype.dispose=function(){Ct(this,null);this.state=8};
function Ct(a,b){ue(a.i);a.i=b}
;var Dt=new zt;function Et(){return Dt.isInitialized()}
function Ft(a){a=void 0===a?{}:a;return Dt.invoke(a)}
;function Gt(a){var b=this;var c=void 0===c?0:c;var d=void 0===d?Tj():d;this.m=c;this.l=d;this.j=new Fd;this.i=a;a={};c=q(this.i.entries());for(d=c.next();!d.done;a={sa:a.sa,Ca:a.Ca},d=c.next()){var e=q(d.value);d=e.next().value;e=e.next().value;a.Ca=d;a.sa=e;d=function(f){return function(){f.sa.gb();b.i[f.Ca].Ta=!0;b.i.every(function(g){return!0===g.Ta})&&b.j.resolve()}}(a);
e=Pj(d,Ht(this,a.sa));this.i[a.Ca]=Object.assign({},a.sa,{gb:d,Pa:e})}}
function It(a){var b=Array.from(a.i.keys()).sort(function(d,e){return Ht(a,a.i[e])-Ht(a,a.i[d])});
b=q(b);for(var c=b.next();!c.done;c=b.next())c=a.i[c.value],void 0===c.Pa||c.Ta||(a.l.S(c.Pa),Pj(c.gb,10))}
Gt.prototype.cancel=function(){for(var a=q(this.i),b=a.next();!b.done;b=a.next())b=b.value,void 0===b.Pa||b.Ta||this.l.S(b.Pa),b.Ta=!0;this.j.resolve()};
function Ht(a,b){var c;return null!=(c=b.priority)?c:a.m}
;function Jt(a){this.state=a;this.plugins=[];this.o=void 0}
Jt.prototype.install=function(){this.plugins.push.apply(this.plugins,fa(Ia.apply(0,arguments)))};
Jt.prototype.transition=function(a,b){var c=this,d=this.F.find(function(f){return f.from===c.state&&f.C===a});
if(d){this.l&&(It(this.l),this.l=void 0);this.state=a;d=d.action.bind(this);var e=this.plugins.filter(function(f){return f[a]}).map(function(f){return f[a]});
d(Kt(this,e,this.o),b)}else throw Error("no transition specified from "+this.state+" to "+a);};
function Kt(a,b,c){return function(){var d=Ia.apply(0,arguments),e=b.filter(function(k){var m;return 10===(null!=(m=null!=c?c:k.priority)?m:0)}),f=b.filter(function(k){var m;
return 10!==(null!=(m=null!=c?c:k.priority)?m:0)});
Tj();var g={};e=q(e);for(var h=e.next();!h.done;g={Da:g.Da},h=e.next())g.Da=h.value,Rj(function(k){return function(){k.Da.ka.apply(k.Da,fa(d))}}(g));
f=f.map(function(k){var m;return{gb:function(){k.ka.apply(k,fa(d))},
priority:null!=(m=null!=c?c:k.priority)?m:0}});
f.length&&(a.l=new Gt(f))}}
da.Object.defineProperties(Jt.prototype,{currentState:{configurable:!0,enumerable:!0,get:function(){return this.state}}});function Lt(a){Jt.call(this,void 0===a?"document_active":a);var b=this;this.o=10;this.i=new Map;this.F=[{from:"document_active",C:"document_disposed_preventable",action:this.v},{from:"document_active",C:"document_disposed",action:this.m},{from:"document_disposed_preventable",C:"document_disposed",action:this.m},{from:"document_disposed_preventable",C:"flush_logs",action:this.s},{from:"document_disposed_preventable",C:"document_active",action:this.j},{from:"document_disposed",C:"flush_logs",action:this.s},
{from:"document_disposed",C:"document_active",action:this.j},{from:"document_disposed",C:"document_disposed",action:function(){}},
{from:"flush_logs",C:"document_active",action:this.j}];window.addEventListener("pagehide",function(c){b.transition("document_disposed",{event:c})});
window.addEventListener("beforeunload",function(c){b.transition("document_disposed_preventable",{event:c})})}
r(Lt,Jt);Lt.prototype.v=function(a,b){if(!this.i.get("document_disposed_preventable")){a(null==b?void 0:b.event);var c,d;if((null==b?0:null==(c=b.event)?0:c.defaultPrevented)||(null==b?0:null==(d=b.event)?0:d.returnValue)){b.event.returnValue||(b.event.returnValue=!0);b.event.defaultPrevented||b.event.preventDefault();this.i=new Map;this.transition("document_active");return}}this.i.set("document_disposed_preventable",!0);this.i.get("document_disposed")?this.transition("flush_logs"):this.transition("document_disposed")};
Lt.prototype.m=function(a,b){this.i.get("document_disposed")?this.transition("document_active"):(a(null==b?void 0:b.event),this.i.set("document_disposed",!0),this.transition("flush_logs"))};
Lt.prototype.s=function(a,b){a(null==b?void 0:b.event);this.transition("document_active")};
Lt.prototype.j=function(){this.i=new Map};function Mt(a){Jt.call(this,void 0===a?"document_visibility_unknown":a);var b=this;this.F=[{from:"document_visibility_unknown",C:"document_visible",action:this.j},{from:"document_visibility_unknown",C:"document_hidden",action:this.i},{from:"document_visibility_unknown",C:"document_foregrounded",action:this.s},{from:"document_visibility_unknown",C:"document_backgrounded",action:this.m},{from:"document_visible",C:"document_hidden",action:this.i},{from:"document_visible",C:"document_foregrounded",action:this.s},
{from:"document_visible",C:"document_visible",action:this.j},{from:"document_foregrounded",C:"document_visible",action:this.j},{from:"document_foregrounded",C:"document_hidden",action:this.i},{from:"document_foregrounded",C:"document_foregrounded",action:this.s},{from:"document_hidden",C:"document_visible",action:this.j},{from:"document_hidden",C:"document_backgrounded",action:this.m},{from:"document_hidden",C:"document_hidden",action:this.i},{from:"document_backgrounded",C:"document_hidden",action:this.i},
{from:"document_backgrounded",C:"document_backgrounded",action:this.m},{from:"document_backgrounded",C:"document_visible",action:this.j}];document.addEventListener("visibilitychange",function(c){"visible"===document.visibilityState?b.transition("document_visible",{event:c}):b.transition("document_hidden",{event:c})});
M("visibility_lifecycles_dynamic_backgrounding")&&(window.addEventListener("blur",function(c){b.transition("document_backgrounded",{event:c})}),window.addEventListener("focus",function(c){b.transition("document_foregrounded",{event:c})}))}
r(Mt,Jt);Mt.prototype.j=function(a,b){a(null==b?void 0:b.event);M("visibility_lifecycles_dynamic_backgrounding")&&this.transition("document_foregrounded")};
Mt.prototype.i=function(a,b){a(null==b?void 0:b.event);M("visibility_lifecycles_dynamic_backgrounding")&&this.transition("document_backgrounded")};
Mt.prototype.m=function(a,b){a(null==b?void 0:b.event)};
Mt.prototype.s=function(a,b){a(null==b?void 0:b.event)};function Nt(){this.i=new Lt;this.j=new Mt}
Nt.prototype.install=function(){var a=Ia.apply(0,arguments);this.i.install.apply(this.i,fa(a));this.j.install.apply(this.j,fa(a))};function Ot(){Nt.call(this);var a={};this.install((a.document_disposed={ka:this.l},a));a={};this.install((a.flush_logs={ka:this.m},a))}
var Pt;r(Ot,Nt);Ot.prototype.m=function(){if(M("web_fp_via_jspb")){var a=new hh,b=cq();b&&a.P(b);b=new Fh;ud(b,380,Gh,a);xp(b);M("web_fp_via_jspb_and_json")&&ek("finalPayload",{csn:cq()})}else ek("finalPayload",{csn:cq()})};
Ot.prototype.l=function(){Pp(Qp)};function Qt(){}
Qt.getInstance=function(){var a=A("ytglobal.storage_");a||(a=new Qt,z("ytglobal.storage_",a));return a};
Qt.prototype.estimate=function(){var a,b,c;return w(function(d){a=navigator;return(null==(b=a.storage)?0:b.estimate)?d.return(a.storage.estimate()):(null==(c=a.webkitTemporaryStorage)?0:c.queryUsageAndQuota)?d.return(Rt()):d.return()})};
function Rt(){var a=navigator;return new Promise(function(b,c){var d;null!=(d=a.webkitTemporaryStorage)&&d.queryUsageAndQuota?a.webkitTemporaryStorage.queryUsageAndQuota(function(e,f){b({usage:e,quota:f})},function(e){c(e)}):c(Error("webkitTemporaryStorage is not supported."))})}
z("ytglobal.storageClass_",Qt);function ck(a,b){var c=this;this.handleError=a;this.i=b;this.j=!1;void 0===self.document||self.addEventListener("beforeunload",function(){c.j=!0});
this.l=Math.random()<=Vh("ytidb_transaction_ended_event_rate_limit",.02)}
ck.prototype.logEvent=function(a,b){switch(a){case "IDB_DATA_CORRUPTED":M("idb_data_corrupted_killswitch")||this.i("idbDataCorrupted",b);break;case "IDB_UNEXPECTEDLY_CLOSED":this.i("idbUnexpectedlyClosed",b);break;case "IS_SUPPORTED_COMPLETED":M("idb_is_supported_completed_killswitch")||this.i("idbIsSupportedCompleted",b);break;case "QUOTA_EXCEEDED":St(this,b);break;case "TRANSACTION_ENDED":this.l&&this.i("idbTransactionEnded",b);break;case "TRANSACTION_UNEXPECTEDLY_ABORTED":a=Object.assign({},b,
{hasWindowUnloaded:this.j}),this.i("idbTransactionAborted",a)}};
function St(a,b){Qt.getInstance().estimate().then(function(c){c=Object.assign({},b,{isSw:void 0===self.document,isIframe:self!==self.top,deviceStorageUsageMbytes:Tt(null==c?void 0:c.usage),deviceStorageQuotaMbytes:Tt(null==c?void 0:c.quota)});a.i("idbQuotaExceeded",c)})}
function Tt(a){return"undefined"===typeof a?"-1":String(Math.ceil(a/1048576))}
;function Ut(a,b,c){I.call(this);var d=this;c=c||L("POST_MESSAGE_ORIGIN")||window.document.location.protocol+"//"+window.document.location.hostname;this.l=b||null;this.targetOrigin="*";this.m=c;this.sessionId=null;this.channel="widget";this.L=!!a;this.B=function(e){a:if(!("*"!=d.m&&e.origin!=d.m||d.l&&e.source!=d.l||"string"!==typeof e.data)){try{var f=JSON.parse(e.data)}catch(g){break a}if(!(null==f||d.L&&(d.sessionId&&d.sessionId!=f.id||d.channel&&d.channel!=f.channel))&&f)switch(f.event){case "listening":"null"!=
e.origin&&(d.m=d.targetOrigin=e.origin);d.l=e.source;d.sessionId=f.id;d.j&&(d.j(),d.j=null);break;case "command":d.o&&(!d.v||0<=cb(d.v,f.func))&&d.o(f.func,f.args,e.origin)}}};
this.v=this.j=this.o=null;window.addEventListener("message",this.B)}
r(Ut,I);Ut.prototype.sendMessage=function(a,b){if(b=b||this.l){this.sessionId&&(a.id=this.sessionId);this.channel&&(a.channel=this.channel);try{var c=JSON.stringify(a);b.postMessage(c,this.targetOrigin)}catch(d){bi(d)}}};
Ut.prototype.I=function(){window.removeEventListener("message",this.B);I.prototype.I.call(this)};function Vt(){this.j=[];this.isReady=!1;this.l={};var a=this.i=new Ut(!!L("WIDGET_ID_ENFORCE")),b=this.lc.bind(this);a.o=b;a.v=null;this.i.channel="widget";if(a=L("WIDGET_ID"))this.i.sessionId=a}
l=Vt.prototype;l.lc=function(a,b,c){"addEventListener"===a&&b?(a=b[0],this.l[a]||"onReady"===a||(this.addEventListener(a,Wt(this,a)),this.l[a]=!0)):this.nb(a,b,c)};
l.nb=function(){};
function Wt(a,b){return function(c){return a.sendMessage(b,c)}}
l.addEventListener=function(){};
l.Yb=function(){this.isReady=!0;this.sendMessage("initialDelivery",this.ab());this.sendMessage("onReady");db(this.j,this.Lb,this);this.j=[]};
l.ab=function(){return null};
function Xt(a,b){a.sendMessage("infoDelivery",b)}
l.Lb=function(a){this.isReady?this.i.sendMessage(a):this.j.push(a)};
l.sendMessage=function(a,b){this.Lb({event:a,info:void 0===b?null:b})};
l.dispose=function(){this.i=null};function Yt(a){return(0===a.search("cue")||0===a.search("load"))&&"loadModule"!==a}
function Zt(a,b,c){if("string"===typeof a)return{videoId:a,startSeconds:b,suggestedQuality:c};b=["endSeconds","startSeconds","mediaContentUrl","suggestedQuality","videoId"];c={};for(var d=0;d<b.length;d++){var e=b[d];a[e]&&(c[e]=a[e])}return c}
function $t(a,b,c,d){if(Pa(a)&&!Array.isArray(a)){b="playlist list listType index startSeconds suggestedQuality".split(" ");c={};for(d=0;d<b.length;d++){var e=b[d];a[e]&&(c[e]=a[e])}return c}b={index:b,startSeconds:c,suggestedQuality:d};"string"===typeof a&&16===a.length?b.list="PL"+a:b.playlist=a;return b}
;function au(a){Vt.call(this);this.listeners=[];this.api=a;this.addEventListener("onReady",this.onReady.bind(this));this.addEventListener("onVideoProgress",this.wc.bind(this));this.addEventListener("onVolumeChange",this.xc.bind(this));this.addEventListener("onApiChange",this.pc.bind(this));this.addEventListener("onPlaybackQualityChange",this.tc.bind(this));this.addEventListener("onPlaybackRateChange",this.uc.bind(this));this.addEventListener("onStateChange",this.vc.bind(this));this.addEventListener("onWebglSettingsChanged",
this.yc.bind(this))}
r(au,Vt);l=au.prototype;
l.nb=function(a,b,c){if(this.api.isExternalMethodAvailable(a,c)){b=b||[];if(0<b.length&&Yt(a)){var d=b;if(Pa(d[0])&&!Array.isArray(d[0]))var e=d[0];else switch(e={},a){case "loadVideoById":case "cueVideoById":e=Zt(d[0],void 0!==d[1]?Number(d[1]):void 0,d[2]);break;case "loadVideoByUrl":case "cueVideoByUrl":e=d[0];"string"===typeof e&&(e={mediaContentUrl:e,startSeconds:void 0!==d[1]?Number(d[1]):void 0,suggestedQuality:d[2]});b:{if((d=e.mediaContentUrl)&&(d=/\/([ve]|embed)\/([^#?]+)/.exec(d))&&d[2]){d=
d[2];break b}d=null}e.videoId=d;e=Zt(e);break;case "loadPlaylist":case "cuePlaylist":e=$t(d[0],d[1],d[2],d[3])}b.length=1;b[0]=e}this.api.handleExternalCall(a,b,c);Yt(a)&&Xt(this,this.ab())}};
l.onReady=function(){var a=this.Yb.bind(this);this.i.j=a};
l.addEventListener=function(a,b){this.listeners.push({eventType:a,listener:b});this.api.addEventListener(a,b)};
l.ab=function(){if(!this.api)return null;var a=this.api.getApiInterface();ib(a,"getVideoData");for(var b={apiInterface:a},c=0,d=a.length;c<d;c++){var e=a[c];if(0===e.search("get")||0===e.search("is")){var f=0;0===e.search("get")?f=3:0===e.search("is")&&(f=2);f=e.charAt(f).toLowerCase()+e.substr(f+1);try{var g=this.api[e]();b[f]=g}catch(h){}}}b.videoData=this.api.getVideoData();b.currentTimeLastUpdated_=Date.now()/1E3;return b};
l.vc=function(a){a={playerState:a,currentTime:this.api.getCurrentTime(),duration:this.api.getDuration(),videoData:this.api.getVideoData(),videoStartBytes:0,videoBytesTotal:this.api.getVideoBytesTotal(),videoLoadedFraction:this.api.getVideoLoadedFraction(),playbackQuality:this.api.getPlaybackQuality(),availableQualityLevels:this.api.getAvailableQualityLevels(),currentTimeLastUpdated_:Date.now()/1E3,playbackRate:this.api.getPlaybackRate(),mediaReferenceTime:this.api.getMediaReferenceTime()};this.api.getVideoUrl&&
(a.videoUrl=this.api.getVideoUrl());this.api.getVideoContentRect&&(a.videoContentRect=this.api.getVideoContentRect());this.api.getProgressState&&(a.progressState=this.api.getProgressState());this.api.getPlaylist&&(a.playlist=this.api.getPlaylist());this.api.getPlaylistIndex&&(a.playlistIndex=this.api.getPlaylistIndex());this.api.getStoryboardFormat&&(a.storyboardFormat=this.api.getStoryboardFormat());Xt(this,a)};
l.tc=function(a){Xt(this,{playbackQuality:a})};
l.uc=function(a){Xt(this,{playbackRate:a})};
l.pc=function(){for(var a=this.api.getOptions(),b={namespaces:a},c=0,d=a.length;c<d;c++){var e=a[c],f=this.api.getOptions(e);b[e]={options:f};for(var g=0,h=f.length;g<h;g++){var k=f[g],m=this.api.getOption(e,k);b[e][k]=m}}this.sendMessage("apiInfoDelivery",b)};
l.xc=function(){Xt(this,{muted:this.api.isMuted(),volume:this.api.getVolume()})};
l.wc=function(a){a={currentTime:a,videoBytesLoaded:this.api.getVideoBytesLoaded(),videoLoadedFraction:this.api.getVideoLoadedFraction(),currentTimeLastUpdated_:Date.now()/1E3,playbackRate:this.api.getPlaybackRate(),mediaReferenceTime:this.api.getMediaReferenceTime()};this.api.getProgressState&&(a.progressState=this.api.getProgressState());Xt(this,a)};
l.yc=function(){var a={sphericalProperties:this.api.getSphericalProperties()};Xt(this,a)};
l.dispose=function(){Vt.prototype.dispose.call(this);for(var a=0;a<this.listeners.length;a++){var b=this.listeners[a];this.api.removeEventListener(b.eventType,b.listener)}this.listeners=[]};function bu(a){I.call(this);this.j={};this.started=!1;this.connection=a;this.connection.subscribe("command",this.Hb,this)}
r(bu,I);l=bu.prototype;l.start=function(){this.started||this.i()||(this.started=!0,this.connection.la("RECEIVING"))};
l.la=function(a,b){this.started&&!this.i()&&this.connection.la(a,b)};
l.Hb=function(a,b,c){if(this.started&&!this.i()){var d=b||{};switch(a){case "addEventListener":"string"===typeof d.event&&this.addListener(d.event);break;case "removeEventListener":"string"===typeof d.event&&this.removeListener(d.event);break;default:this.api.isReady()&&this.api.isExternalMethodAvailable(a,c||null)&&(b=cu(a,b||{}),c=this.api.handleExternalCall(a,b,c||null),(c=du(a,c))&&this.la(a,c))}}};
l.addListener=function(a){if(!(a in this.j)){var b=this.qc.bind(this,a);this.j[a]=b;this.addEventListener(a,b)}};
l.qc=function(a,b){this.started&&!this.i()&&this.connection.la(a,this.Za(a,b))};
l.Za=function(a,b){if(null!=b)return{value:b}};
l.removeListener=function(a){a in this.j&&(this.removeEventListener(a,this.j[a]),delete this.j[a])};
l.I=function(){var a=this.connection;a.i()||sg(a.j,"command",this.Hb,this);this.connection=null;for(var b in this.j)this.j.hasOwnProperty(b)&&this.removeListener(b);I.prototype.I.call(this)};function eu(a,b){bu.call(this,b);this.api=a;this.start()}
r(eu,bu);eu.prototype.addEventListener=function(a,b){this.api.addEventListener(a,b)};
eu.prototype.removeEventListener=function(a,b){this.api.removeEventListener(a,b)};
function cu(a,b){switch(a){case "loadVideoById":return a=Zt(b),[a];case "cueVideoById":return a=Zt(b),[a];case "loadVideoByPlayerVars":return[b];case "cueVideoByPlayerVars":return[b];case "loadPlaylist":return a=$t(b),[a];case "cuePlaylist":return a=$t(b),[a];case "seekTo":return[b.seconds,b.allowSeekAhead];case "playVideoAt":return[b.index];case "setVolume":return[b.volume];case "setPlaybackQuality":return[b.suggestedQuality];case "setPlaybackRate":return[b.suggestedRate];case "setLoop":return[b.loopPlaylists];
case "setShuffle":return[b.shufflePlaylist];case "getOptions":return[b.module];case "getOption":return[b.module,b.option];case "setOption":return[b.module,b.option,b.value];case "handleGlobalKeyDown":return[b.keyCode,b.shiftKey,b.ctrlKey,b.altKey,b.metaKey,b.key,b.code]}return[]}
function du(a,b){switch(a){case "isMuted":return{muted:b};case "getVolume":return{volume:b};case "getPlaybackRate":return{playbackRate:b};case "getAvailablePlaybackRates":return{availablePlaybackRates:b};case "getVideoLoadedFraction":return{videoLoadedFraction:b};case "getPlayerState":return{playerState:b};case "getCurrentTime":return{currentTime:b};case "getPlaybackQuality":return{playbackQuality:b};case "getAvailableQualityLevels":return{availableQualityLevels:b};case "getDuration":return{duration:b};
case "getVideoUrl":return{videoUrl:b};case "getVideoEmbedCode":return{videoEmbedCode:b};case "getPlaylist":return{playlist:b};case "getPlaylistIndex":return{playlistIndex:b};case "getOptions":return{options:b};case "getOption":return{option:b}}}
eu.prototype.Za=function(a,b){switch(a){case "onReady":return;case "onStateChange":return{playerState:b};case "onPlaybackQualityChange":return{playbackQuality:b};case "onPlaybackRateChange":return{playbackRate:b};case "onError":return{errorCode:b}}return bu.prototype.Za.call(this,a,b)};
eu.prototype.I=function(){bu.prototype.I.call(this);delete this.api};function fu(a){a=void 0===a?!1:a;I.call(this);this.j=new J(a);we(this,Wa(ue,this.j))}
Xa(fu,I);fu.prototype.subscribe=function(a,b,c){return this.i()?0:this.j.subscribe(a,b,c)};
fu.prototype.m=function(a,b){this.i()||this.j.ia.apply(this.j,arguments)};function gu(a,b,c){fu.call(this);this.l=a;this.destination=b;this.id=c}
r(gu,fu);gu.prototype.la=function(a,b){this.i()||this.l.la(this.destination,this.id,a,b)};
gu.prototype.I=function(){this.destination=this.l=null;fu.prototype.I.call(this)};function hu(a,b,c){I.call(this);this.destination=a;this.origin=c;this.j=wn(window,"message",this.l.bind(this));this.connection=new gu(this,a,b);we(this,Wa(ue,this.connection))}
r(hu,I);hu.prototype.la=function(a,b,c,d){this.i()||a!==this.destination||(a={id:b,command:c},d&&(a.data=d),this.destination.postMessage(Vf(a),this.origin))};
hu.prototype.l=function(a){var b;if(b=!this.i())if(b=a.origin===this.origin)a:{b=this.destination;do{b:{var c=a.source;do{if(c===b){c=!0;break b}if(c===c.parent)break;c=c.parent}while(null!=c);c=!1}if(c){b=!0;break a}b=b.opener}while(null!=b);b=!1}if(b&&(b=a.data,"string"===typeof b)){try{b=JSON.parse(b)}catch(d){return}b.command&&(c=this.connection,c.i()||c.m("command",b.command,b.data,a.origin))}};
hu.prototype.I=function(){xn(this.j);this.destination=null;I.prototype.I.call(this)};function iu(a){a=a||{};var b={},c={};this.url=a.url||"";this.args=a.args||rb(b);this.assets=a.assets||{};this.attrs=a.attrs||rb(c);this.fallback=a.fallback||null;this.fallbackMessage=a.fallbackMessage||null;this.html5=!!a.html5;this.disable=a.disable||{};this.loaded=!!a.loaded;this.messages=a.messages||{}}
iu.prototype.clone=function(){var a=new iu,b;for(b in this)if(this.hasOwnProperty(b)){var c=this[b];"object"==Ma(c)?a[b]=rb(c):a[b]=c}return a};var ju=/cssbin\/(?:debug-)?([a-zA-Z0-9_-]+?)(?:-2x|-web|-rtl|-vfl|.css)/;function ku(a){a=a||"";if(window.spf){var b=a.match(ju);spf.style.load(a,b?b[1]:"",void 0)}else lu(a)}
function lu(a){var b=mu(a),c=document.getElementById(b),d=c&&gt(c,"loaded");d||c&&!d||(c=nu(a,b,function(){gt(c,"loaded")||(et(c),Mn(b),ui(Wa(Nn,b),0))}))}
function nu(a,b,c){var d=document.createElement("link");d.id=b;d.onload=function(){c&&setTimeout(c,0)};
a=Hb(a);Ub(d,a);(document.getElementsByTagName("head")[0]||document.body).appendChild(d);return d}
function mu(a){var b=Rd("A");Bb("This URL is never added to the DOM");Tb(b,new Jb(a,Kb));a=b.href.replace(/^[a-zA-Z]+:\/\//,"//");return"css-"+Yb(a)}
;function ou(){I.call(this);this.j=[]}
r(ou,I);ou.prototype.I=function(){for(;this.j.length;){var a=this.j.pop();a.target.removeEventListener(a.name,a.ka,void 0)}I.prototype.I.call(this)};function pu(){ou.apply(this,arguments)}
r(pu,ou);function qu(a,b,c,d){I.call(this);var e=this;this.N=b;this.webPlayerContextConfig=d;this.Va=!1;this.api={};this.Ea=this.v=null;this.R=new J;this.j={};this.ea=this.Fa=this.elementId=this.Wa=this.config=null;this.W=!1;this.m=this.B=null;this.Ga={};this.Pb=["onReady"];this.lastError=null;this.ob=NaN;this.L={};this.Qb=new pu(this);this.na=0;this.l=this.o=a;we(this,Wa(ue,this.R));ru(this);su(this);we(this,Wa(ue,this.Qb));c?this.na=ui(function(){e.loadNewVideoConfig(c)},0):d&&(tu(this),uu(this))}
r(qu,I);l=qu.prototype;l.getId=function(){return this.N};
l.loadNewVideoConfig=function(a){if(!this.i()){this.na&&(vi(this.na),this.na=0);var b=a||{};b instanceof iu||(b=new iu(b));this.config=b;this.setConfig(a);uu(this);this.isReady()&&vu(this)}};
function tu(a){var b;a.webPlayerContextConfig?b=a.webPlayerContextConfig.rootElementId:b=a.config.attrs.id;a.elementId=b||a.elementId;"video-player"===a.elementId&&(a.elementId=a.N,a.webPlayerContextConfig?a.webPlayerContextConfig.rootElementId=a.N:a.config.attrs.id=a.N);var c;(null==(c=a.l)?void 0:c.id)===a.elementId&&(a.elementId+="-player",a.webPlayerContextConfig?a.webPlayerContextConfig.rootElementId=a.elementId:a.config.attrs.id=a.elementId)}
l.setConfig=function(a){this.Wa=a;this.config=wu(a);tu(this);if(!this.Fa){var b;this.Fa=xu(this,(null==(b=this.config.args)?void 0:b.jsapicallback)||"onYouTubePlayerReady")}this.config.args?this.config.args.jsapicallback=null:this.config.args={jsapicallback:null};var c;if(null==(c=this.config)?0:c.attrs)a=this.config.attrs,(b=a.width)&&this.l&&(this.l.style.width=ee(Number(b)||b)),(a=a.height)&&this.l&&(this.l.style.height=ee(Number(a)||a))};
function vu(a){if(a.config&&!0!==a.config.loaded)if(a.config.loaded=!0,!a.config.args||"0"!==a.config.args.autoplay&&0!==a.config.args.autoplay&&!1!==a.config.args.autoplay){var b;a.api.loadVideoByPlayerVars(null!=(b=a.config.args)?b:null)}else a.api.cueVideoByPlayerVars(a.config.args)}
function yu(a){var b=!0,c=zu(a);c&&a.config&&(a=Au(a),b=gt(c,"version")===a);return b&&!!A("yt.player.Application.create")}
function uu(a){if(!a.i()&&!a.W){var b=yu(a);if(b&&"html5"===(zu(a)?"html5":null))a.ea="html5",a.isReady()||Bu(a);else if(Cu(a),a.ea="html5",b&&a.m&&a.o)a.o.appendChild(a.m),Bu(a);else{a.config&&(a.config.loaded=!0);var c=!1;a.B=function(){c=!0;var d=Du(a,"player_bootstrap_method")?A("yt.player.Application.createAlternate")||A("yt.player.Application.create"):A("yt.player.Application.create");var e=a.config?wu(a.config):void 0;d&&d(a.o,e,a.webPlayerContextConfig);Bu(a)};
a.W=!0;b?a.B():(lt(Au(a),a.B),(b=Eu(a))&&ku(b),Fu(a)&&!c&&z("yt.player.Application.create",null))}}}
function zu(a){var b=Qd(a.elementId);!b&&a.l&&a.l.querySelector&&(b=a.l.querySelector("#"+a.elementId));return b}
function Bu(a){if(!a.i()){var b=zu(a),c=!1;b&&b.getApiInterface&&b.getApiInterface()&&(c=!0);if(c){a.W=!1;if(!Du(a,"html5_remove_not_servable_check_killswitch")){var d;if((null==b?0:b.isNotServable)&&a.config&&(null==b?0:b.isNotServable(null==(d=a.config.args)?void 0:d.video_id)))return}Gu(a)}else a.ob=ui(function(){Bu(a)},50)}}
function Gu(a){ru(a);a.Va=!0;var b=zu(a);if(b){a.v=Hu(a,b,"addEventListener");a.Ea=Hu(a,b,"removeEventListener");var c=b.getApiInterface();c=c.concat(b.getInternalApiInterface());for(var d=a.api,e=0;e<c.length;e++){var f=c[e];d[f]||(d[f]=Hu(a,b,f))}}for(var g in a.j)a.j.hasOwnProperty(g)&&a.v&&a.v(g,a.j[g]);vu(a);a.Fa&&a.Fa(a.api);a.R.ia("onReady",a.api)}
function Hu(a,b,c){var d=b[c];return function(){var e=Ia.apply(0,arguments);try{return a.lastError=null,d.apply(b,e)}catch(f){"sendAbandonmentPing"!==c&&(f.params=c,a.lastError=f,Lp(f))}}}
function ru(a){a.Va=!1;if(a.Ea)for(var b in a.j)a.j.hasOwnProperty(b)&&a.Ea(b,a.j[b]);for(var c in a.L)a.L.hasOwnProperty(c)&&vi(Number(c));a.L={};a.v=null;a.Ea=null;b=a.api;for(var d in b)b.hasOwnProperty(d)&&(b[d]=null);b.addEventListener=function(e,f){a.addEventListener(e,f)};
b.removeEventListener=function(e,f){a.removeEventListener(e,f)};
b.destroy=function(){a.dispose()};
b.getLastError=function(){return a.getLastError()};
b.getPlayerType=function(){return a.getPlayerType()};
b.getCurrentVideoConfig=function(){return a.Wa};
b.loadNewVideoConfig=function(e){a.loadNewVideoConfig(e)};
b.isReady=function(){return a.isReady()}}
l.isReady=function(){return this.Va};
function su(a){a.addEventListener("WATCH_LATER_VIDEO_ADDED",function(b){Mn("WATCH_LATER_VIDEO_ADDED",b)});
a.addEventListener("WATCH_LATER_VIDEO_REMOVED",function(b){Mn("WATCH_LATER_VIDEO_REMOVED",b)})}
l.addEventListener=function(a,b){var c=this,d=xu(this,b);d&&(0<=cb(this.Pb,a)||this.j[a]||(b=Iu(this,a),this.v&&this.v(a,b)),this.R.subscribe(a,d),"onReady"===a&&this.isReady()&&ui(function(){d(c.api)},0))};
l.removeEventListener=function(a,b){this.i()||(b=xu(this,b))&&sg(this.R,a,b)};
function xu(a,b){var c=b;if("string"===typeof b){if(a.Ga[b])return a.Ga[b];c=function(){var d=Ia.apply(0,arguments),e=A(b);if(e)try{e.apply(y,d)}catch(f){Kp(f)}};
a.Ga[b]=c}return c?c:null}
function Iu(a,b){var c="ytPlayer"+b+a.N;a.j[b]=c;y[c]=function(d){var e=ui(function(){if(!a.i()){a.R.ia(b,null!=d?d:void 0);var f=a.L,g=String(e);g in f&&delete f[g]}},0);
ob(a.L,String(e))};
return c}
l.getPlayerType=function(){return this.ea||(zu(this)?"html5":null)};
l.getLastError=function(){return this.lastError};
function Cu(a){a.cancel();ru(a);a.ea=null;a.config&&(a.config.loaded=!1);var b=zu(a);b&&(yu(a)||!Fu(a)?a.m=b:(b&&b.destroy&&b.destroy(),a.m=null));if(a.o)for(a=a.o;b=a.firstChild;)a.removeChild(b)}
l.cancel=function(){this.B&&rt(Au(this),this.B);vi(this.ob);this.W=!1};
l.I=function(){Cu(this);if(this.m&&this.config&&this.m.destroy)try{this.m.destroy()}catch(b){Kp(b)}this.Ga=null;for(var a in this.j)this.j.hasOwnProperty(a)&&(y[this.j[a]]=null);this.Wa=this.config=this.api=null;delete this.o;delete this.l;I.prototype.I.call(this)};
function Fu(a){var b,c;a=null==(b=a.config)?void 0:null==(c=b.args)?void 0:c.fflags;return!!a&&-1!==a.indexOf("player_destroy_old_version=true")}
function Au(a){return a.webPlayerContextConfig?a.webPlayerContextConfig.jsUrl:(a=a.config.assets)?a.js:""}
function Eu(a){return a.webPlayerContextConfig?a.webPlayerContextConfig.cssUrl:(a=a.config.assets)?a.css:""}
function Du(a,b){if(a.webPlayerContextConfig)var c=a.webPlayerContextConfig.serializedExperimentFlags;else{var d;if(null==(d=a.config)?0:d.args)c=a.config.args.fflags}return"true"===hi(c||"","&")[b]}
function wu(a){for(var b={},c=q(Object.keys(a)),d=c.next();!d.done;d=c.next()){d=d.value;var e=a[d];b[d]="object"===typeof e?rb(e):e}return b}
;var Ju={},Ku="player_uid_"+(1E9*Math.random()>>>0);function Lu(a,b,c){var d="player";c=void 0===c?!0:c;d="string"===typeof d?Qd(d):d;var e=Ku+"_"+Qa(d),f=Ju[e];if(f&&c)return Mu(a,b)?f.api.loadVideoByPlayerVars(a.args||null):f.loadNewVideoConfig(a),f.api;f=new qu(d,e,a,b);Ju[e]=f;Mn("player-added",f.api);we(f,function(){delete Ju[f.getId()]});
return f.api}
function Mu(a,b){return b&&b.serializedExperimentFlags?b.serializedExperimentFlags.includes("web_player_remove_playerproxy=true"):a&&a.args&&a.args.fflags?a.args.fflags.includes("web_player_remove_playerproxy=true"):!1}
;var Nu=null,Ou=null,Pu=null;function Qu(){var a=Nu.getVideoData(1);a=a.title?a.title+" - YouTube":"YouTube";document.title!==a&&(document.title=a)}
;function Ru(a,b,c){a="ST-"+Yb(a).toString(36);b=b?ec(b):"";c=c||5;rq()&&fj(a,b,c)}
;function Su(a,b,c){b=void 0===b?{}:b;c=void 0===c?!1:c;var d=L("EVENT_ID");d&&(b.ei||(b.ei=d));if(b){d=a;var e=void 0===e?!0:e;var f=L("VALID_SESSION_TEMPDATA_DOMAINS",[]),g=bc(window.location.href);g&&f.push(g);g=bc(d);if(0<=cb(f,g)||!g&&0==d.lastIndexOf("/",0))if(M("autoescape_tempdata_url")&&(f=document.createElement("a"),Tb(f,d),d=f.href),d&&(d=cc(d),f=d.indexOf("#"),d=0>f?d:d.slice(0,f)))if(e&&!b.csn&&(b.itct||b.ved)&&(b=Object.assign({csn:cq()},b)),h){var h=parseInt(h,10);isFinite(h)&&0<h&&
Ru(d,b,h)}else Ru(d,b)}if(c)return!1;if((window.ytspf||{}).enabled)spf.navigate(a);else{var k=void 0===k?{}:k;var m=void 0===m?"":m;var p=void 0===p?window:p;c=p.location;a=fc(a,k)+m;var u=void 0===u?de:u;a:{u=void 0===u?de:u;for(k=0;k<u.length;++k)if(m=u[k],m instanceof be&&m.isValid(a)){u=new Kd(a,Id);break a}u=void 0}c.href=Md(u||Ld)}return!0}
;z("yt.setConfig",Sh);z("yt.config.set",Sh);z("yt.setMsg",hq);z("yt.msgs.set",hq);z("yt.logging.errors.log",Kp);
z("writeEmbed",function(){var a=L("PLAYER_CONFIG");if(!a){var b=L("PLAYER_VARS");b&&(a={args:b})}Aq(!0);"gvn"===a.args.ps&&(document.body.style.backgroundColor="transparent");a.attrs||(a.attrs={width:"100%",height:"100%",id:"video-player"});var c=document.referrer;b=L("POST_MESSAGE_ORIGIN");window!==window.top&&c&&c!==document.URL&&(a.args.loaderUrl=c);M("embeds_js_api_set_1p_cookie")&&(c=mi(window.location.href),c.embedsTokenValue&&(a.args.embedsTokenValue=c.embedsTokenValue));Xr();if((c=L("WEB_PLAYER_CONTEXT_CONFIGS"))&&
"WEB_PLAYER_CONTEXT_CONFIG_ID_EMBEDDED_PLAYER"in c){c=c.WEB_PLAYER_CONTEXT_CONFIG_ID_EMBEDDED_PLAYER;if(!c.serializedForcedExperimentIds){var d=mi(window.location.href);d.forced_experiments&&(c.serializedForcedExperimentIds=d.forced_experiments)}Nu=Lu(a,c,!1)}else Nu=Lu(a);Nu.addEventListener("onVideoDataChange",Qu);a=L("POST_MESSAGE_ID","player");L("ENABLE_JS_API")?Pu=new au(Nu):L("ENABLE_POST_API")&&"string"===typeof a&&"string"===typeof b&&(Ou=new hu(window.parent,a,b),Pu=new eu(Nu,Ou.connection));
ut();M("ytidb_create_logger_embed_killswitch")||bk();a={};Pt||(Pt=new Ot);Pt.install((a.flush_logs={ka:function(){So()}},a));
M("embeds_web_enable_new_nwl")?Pm():Xm();M("ytidb_clear_embedded_player")&&gf.M(function(){var e;if(!Ds){Kq||(Kq=new Hq);var f=Kq;var g={kc:Cs,Nb:Bs};f.providers.set(g.kc,g);g={rb:{feedbackEndpoint:Vq(xs),modifyChannelNotificationPreferenceEndpoint:Vq(ys),playlistEditEndpoint:Vq(zs),subscribeEndpoint:Vq(vs),unsubscribeEndpoint:Vq(ws),webPlayerShareEntityServiceEndpoint:Vq(As)}};var h=M("web_enable_client_location_service")?Rq.getInstance():void 0,k={};h&&(k.client_location=h);if(void 0===m){Bq.i||
(Bq.i=new Bq);var m=Bq.i}void 0===e&&(e=f.resolve(Cs));ks(g,e,m,k);Ds=js.i}dt()})});
var Tu=$h(function(){bs();var a=jj.getInstance(),b=mj(119),c=1<window.devicePixelRatio;if(document.body&&Gf(document.body,"exp-invert-logo"))if(c&&!Gf(document.body,"inverted-hdpi")){var d=document.body;if(d.classList)d.classList.add("inverted-hdpi");else if(!Gf(d,"inverted-hdpi")){var e=Ef(d);Ff(d,e+(0<e.length?" inverted-hdpi":"inverted-hdpi"))}}else!c&&Gf(document.body,"inverted-hdpi")&&Hf();if(b!=c){b="f"+(Math.floor(119/31)+1);d=nj(b)||0;d=c?d|67108864:d&-67108865;0==d?delete ij[b]:(c=d.toString(16),
ij[b]=c.toString());c=!0;M("web_secure_pref_cookie_killswitch")&&(c=!1);b=a.i;d=[];for(var f in ij)d.push(f+"="+encodeURIComponent(String(ij[f])));fj(b,d.join("&"),63072E3,a.j,c)}Ns.i||(Ns.i=new Ns);a=Ns.i;f=16623;var g=void 0===g?{}:g;Object.values(iq).includes(f)||(Lp(new hk("createClientScreen() called with a non-page VE",f)),f=83769);g.isHistoryNavigation||a.i.push({rootVe:f,key:g.key||""});a.s=[];a.F=[];g.ub?Qs(a,f,g):Rs(a,f,g)}),Uu=$h(function(){Nu&&Nu.sendAbandonmentPing&&Nu.sendAbandonmentPing();
L("PL_ATT")&&Dt.dispose();for(var a=gf,b=0,c=st.length;b<c;b++)a.S(st[b]);st.length=0;qt("//static.doubleclick.net/instream/ad_status.js");tt=!1;Sh("DCLKSTAT",0);ve(Pu,Ou);Nu&&(Nu.removeEventListener("onVideoDataChange",Qu),Nu.destroy())});
window.addEventListener?(window.addEventListener("load",Tu),window.addEventListener("pagehide",Uu)):window.attachEvent&&(window.attachEvent("onload",Tu),window.attachEvent("onunload",Uu));z("yt.abuse.player.botguardInitialized",A("yt.abuse.player.botguardInitialized")||Et);z("yt.abuse.player.invokeBotguard",A("yt.abuse.player.invokeBotguard")||Ft);z("yt.abuse.dclkstatus.checkDclkStatus",A("yt.abuse.dclkstatus.checkDclkStatus")||xt);z("yt.player.exports.navigate",A("yt.player.exports.navigate")||Su);
z("yt.util.activity.init",A("yt.util.activity.init")||Bn);z("yt.util.activity.getTimeSinceActive",A("yt.util.activity.getTimeSinceActive")||En);z("yt.util.activity.setTimestamp",A("yt.util.activity.setTimestamp")||Cn);}).call(this);
