package gr.ictpro.jsalatas.ane.locale
{
	import flash.events.EventDispatcher;
	import flash.events.IEventDispatcher;
	import flash.external.ExtensionContext;
	
	public class Locale  extends EventDispatcher
	{
		private var _ctx:ExtensionContext;

		public function Locale(target:IEventDispatcher=null)
		{
			super(target);
			_ctx = ExtensionContext.createExtensionContext("gr.ictpro.jsalatas.ane.locale", null);
		}
		
		public function dispose():void
		{
			_ctx.dispose();
		}
		
		public function isSupported():Boolean
		{
			return _ctx.call("isSupported");
		}
		
		public function getLocale():String 
		{
			return _ctx.call("getLocale") as String;
		}

	}
}