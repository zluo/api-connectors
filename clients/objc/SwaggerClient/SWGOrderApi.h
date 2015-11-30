#import <Foundation/Foundation.h>
#import "SWGError.h"
#import "SWGOrder.h"
#import "SWGInlineResponse200.h"
#import "SWGLiquidationOrder.h"
#import "SWGObject.h"
#import "SWGApiClient.h"


/**
 * NOTE: This class is auto generated by the swagger code generator program. 
 * https://github.com/swagger-api/swagger-codegen 
 * Do not edit the class manually.
 */

@interface SWGOrderApi: NSObject

@property(nonatomic, assign)SWGApiClient *apiClient;

-(instancetype) initWithApiClient:(SWGApiClient *)apiClient;
-(void) addHeader:(NSString*)value forKey:(NSString*)key;
-(unsigned long) requestQueueSize;
+(SWGOrderApi*) apiWithHeader:(NSString*)headerValue key:(NSString*)key;
+(SWGOrderApi*) sharedAPI;
///
///
/// Get your orders.
/// To get open orders only, send {\"open\": true} in the filter param.
///
/// @param symbol Instrument symbol. Send a bare series (e.g. XBU) to get data for the nearest expiring contract in that series.\n\nYou can also send a timeframe, e.g. &#39;XBU:monthly&#39;. Timeframes are &#39;daily&#39;, &#39;weekly&#39;, &#39;monthly&#39;, &#39;quarterly&#39;, and &#39;biquarterly&#39;.
/// @param filter Generic table filter. Send JSON key/value pairs, such as {\&quot;key\&quot;: \&quot;value\&quot;}. You can key on individual fields, and do more advanced querying on timestamps. See &lt;a href=\&quot;http://localhost:2001/app/restAPI#timestamp-filters\&quot;&gt;http://localhost:2001/app/restAPI#timestamp-filters&lt;/a&gt; for more details.
/// @param columns Array of column names to fetch. If omitted, will return all columns.\n\nNote that this method will always return item keys, even when not specified, so you may receive more columns that you expect.
/// @param count Number of results to fetch.
/// @param start Starting point for results.
/// @param reverse If true, will sort results newest first.
/// @param startTime Starting date filter for results.
/// @param endTime Ending date filter for results.
/// 
///
/// @return NSArray<SWGOrder>*
-(NSNumber*) orderGetOrdersWithCompletionBlock :(NSString*) symbol 
     filter:(NSString*) filter 
     columns:(NSString*) columns 
     count:(NSNumber*) count 
     start:(NSNumber*) start 
     reverse:(NSNumber*) reverse 
     startTime:(NSDate*) startTime 
     endTime:(NSDate*) endTime 
    
    completionHandler: (void (^)(NSArray<SWGOrder>* output, NSError* error))completionBlock;
    


///
///
/// Create a new order.
/// This endpoint is used for placing orders. Valid order types are 'Limit' and 'StopLimit'. If none is provided, BitMEX will assume a Limit Order.\n\nA note on API tools: if you want to keep track of order IDs yourself, set a unique clOrdID per order. This ID will come back as a property on the order and any related executions (including on the WebSocket), and can be used to get or cancel the order. Max length is 36 characters.\n\nTo generate a clOrdID, consider setting a prefix, and incrementing a counter or generating a UUID. Some UUIDs are longer than 36 characters, so use a url-safe base64 encoding. For example, the prefix 'bmex_mm_' and the UUID '7fbd6545-bb0c-11e4-a273-6003088a7c04' creates 'bmex_mm_f71lRbsMEeSic2ADCIp8BA'.\n\nSee the BitMEX <a href='https://github.com/BitMEX/market-maker/blob/22c75a2b6db63e20212813e9afdb845db1b09b2a/bitmex.py#L152'>Reference Market Maker</a> for an example of how to use and generate clOrdIDs.
///
/// @param symbol Instrument symbol.
/// @param quantity Quantity. Use positive numbers to buy, negative to sell.
/// @param price Order price.
/// @param timeInForce Time in force. Valid options: &#39;IOC&#39; (Immediate-Or-Cancel), &#39;GTC&#39; (Good-Till-Cancelled).
/// @param type Order type. Available: &#39;Limit&#39;, &#39;StopLimit&#39;
/// @param stopPrice If order type is &#39;StopLimit&#39;, this is the trigger/stop price.
/// @param clOrdID Optional Client Order ID to give this order. This ID will come back on any execution messages tied to this order.
/// 
///
/// @return SWGOrder*
-(NSNumber*) orderNewOrderWithCompletionBlock :(NSString*) symbol 
     quantity:(NSNumber*) quantity 
     price:(NSNumber*) price 
     timeInForce:(NSString*) timeInForce 
     type:(NSString*) type 
     stopPrice:(NSNumber*) stopPrice 
     clOrdID:(NSString*) clOrdID 
    
    completionHandler: (void (^)(SWGOrder* output, NSError* error))completionBlock;
    


///
///
/// Cancel order(s). Send multiple order IDs to cancel in bulk.
/// Either an orderID or a clOrdID must be provided.
///
/// @param orderID Order ID(s).
/// @param clOrdID Client Order ID(s). See POST /order.
/// @param text Optional cancellation annotation. e.g. &#39;Spread Exceeded&#39;
/// 
///
/// @return NSArray<SWGOrder>*
-(NSNumber*) orderCancelOrderWithCompletionBlock :(NSString*) orderID 
     clOrdID:(NSString*) clOrdID 
     text:(NSString*) text 
    
    completionHandler: (void (^)(NSArray<SWGOrder>* output, NSError* error))completionBlock;
    


///
///
/// Cancels all of your orders.
/// 
///
/// @param symbol Optional symbol. If provided, only cancels orders for that symbol.
/// @param filter Optional filter for cancellation. Use to only cancel some orders, e.g. `{\&quot;side\&quot;: \&quot;Buy\&quot;}`.
/// @param text Optional cancellation annotation. e.g. &#39;Spread Exceeded&#39;
/// 
///
/// @return SWGInlineResponse200*
-(NSNumber*) orderCancelAllWithCompletionBlock :(NSString*) symbol 
     filter:(NSString*) filter 
     text:(NSString*) text 
    
    completionHandler: (void (^)(SWGInlineResponse200* output, NSError* error))completionBlock;
    


///
///
/// Automatically cancel all your orders after a specified timeout.
/// Useful as a dead-man's switch to ensure your orders are canceled in case of an outage. If called repeatedly, the existing offset will be canceled and a new one will be inserted in its place. <br><br>Example usage: call this route at 15s intervals with an offset of 60000 (60s). If this route is not called within 60 seconds, all your orders will be automatically canceled.<br><br>This is also available via <a href=\"https://www.bitmex.com/app/wsAPI#dead-man-s-switch-auto-cancel-\">WebSocket</a>.
///
/// @param timeout Timeout in ms. Set to 0 to cancel this timer.
/// 
///
/// @return SWGInlineResponse200*
-(NSNumber*) orderCancelAllAfterWithCompletionBlock :(NSNumber*) timeout 
    
    completionHandler: (void (^)(SWGInlineResponse200* output, NSError* error))completionBlock;
    


///
///
/// Close a position with a market order.
/// If no price is specified, a market order will be submitted to close the entirety of your position. Be careful with market orders as you may not be filled at a favorable price.
///
/// @param symbol Symbol of position to close.
/// @param price Optional limit price.
/// 
///
/// @return SWGOrder*
-(NSNumber*) orderClosePositionWithCompletionBlock :(NSString*) symbol 
     price:(NSNumber*) price 
    
    completionHandler: (void (^)(SWGOrder* output, NSError* error))completionBlock;
    


///
///
/// Get open liquidation orders.
/// 
///
/// @param filter Filter. For example, send {\&quot;symbol\&quot;: \&quot;XBT24H\&quot;}.
/// 
///
/// @return NSArray<SWGLiquidationOrder>*
-(NSNumber*) orderGetCloseOutOrdersWithCompletionBlock :(NSString*) filter 
    
    completionHandler: (void (^)(NSArray<SWGLiquidationOrder>* output, NSError* error))completionBlock;
    



@end