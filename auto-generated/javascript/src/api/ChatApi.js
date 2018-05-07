/**
 * BitMEX API
 * ## REST API for the BitMEX Trading Platform  [View Changelog](/app/apiChangelog)    #### Getting Started   ##### Fetching Data  All REST endpoints are documented below. You can try out any query right from this interface.  Most table queries accept `count`, `start`, and `reverse` params. Set `reverse=true` to get rows newest-first.  Additional documentation regarding filters, timestamps, and authentication is available in [the main API documentation](https://www.bitmex.com/app/restAPI).  *All* table data is available via the [Websocket](/app/wsAPI). We highly recommend using the socket if you want to have the quickest possible data without being subject to ratelimits.  ##### Return Types  By default, all data is returned as JSON. Send `?_format=csv` to get CSV data or `?_format=xml` to get XML data.  ##### Trade Data Queries  *This is only a small subset of what is available, to get you started.*  Fill in the parameters and click the `Try it out!` button to try any of these queries.  * [Pricing Data](#!/Quote/Quote_get)  * [Trade Data](#!/Trade/Trade_get)  * [OrderBook Data](#!/OrderBook/OrderBook_getL2)  * [Settlement Data](#!/Settlement/Settlement_get)  * [Exchange Statistics](#!/Stats/Stats_history)  Every function of the BitMEX.com platform is exposed here and documented. Many more functions are available.  ##### Swagger Specification  [⇩ Download Swagger JSON](swagger.json)    ## All API Endpoints  Click to expand a section. 
 *
 * OpenAPI spec version: 1.2.0
 * Contact: support@bitmex.com
 *
 * NOTE: This class is auto generated by the swagger code generator program.
 * https://github.com/swagger-api/swagger-codegen.git
 * Do not edit the class manually.
 *
 */


import ApiClient from "../ApiClient";
import Chat from '../model/Chat';
import ChatChannel from '../model/ChatChannel';
import ConnectedUsers from '../model/ConnectedUsers';
import Error from '../model/Error';

/**
* Chat service.
* @module api/ChatApi
* @version 1.2.0
*/
export default class ChatApi {

    /**
    * Constructs a new ChatApi. 
    * @alias module:api/ChatApi
    * @class
    * @param {module:ApiClient} [apiClient] Optional API client implementation to use,
    * default to {@link module:ApiClient#instance} if unspecified.
    */
    constructor(apiClient) {
        this.apiClient = apiClient || ApiClient.instance;
    }


    /**
     * Callback function to receive the result of the chatGet operation.
     * @callback module:api/ChatApi~chatGetCallback
     * @param {String} error Error message, if any.
     * @param {Array.<module:model/Chat>} data The data returned by the service call.
     * @param {String} response The complete HTTP response.
     */

    /**
     * Get chat messages.
     * @param {Object} opts Optional parameters
     * @param {Number} opts.count Number of results to fetch. (default to 100)
     * @param {Number} opts.start Starting ID for results. (default to 0)
     * @param {Boolean} opts.reverse If true, will sort results newest first. (default to true)
     * @param {Number} opts.channelID Channel id. GET /chat/channels for ids. Leave blank for all.
     * @param {module:api/ChatApi~chatGetCallback} callback The callback function, accepting three arguments: error, data, response
     * data is of type: {@link Array.<module:model/Chat>}
     */
    chatGet(opts, callback) {
      opts = opts || {};
      let postBody = null;


      let pathParams = {
      };
      let queryParams = {
        'count': opts['count'],
        'start': opts['start'],
        'reverse': opts['reverse'],
        'channelID': opts['channelID']
      };
      let headerParams = {
      };
      let formParams = {
      };

      let authNames = [];
      let contentTypes = ['application/json', 'application/x-www-form-urlencoded'];
      let accepts = ['application/json', 'application/xml', 'text/xml', 'application/javascript', 'text/javascript'];
      let returnType = [Chat];

      return this.apiClient.callApi(
        '/chat', 'GET',
        pathParams, queryParams, headerParams, formParams, postBody,
        authNames, contentTypes, accepts, returnType, callback
      );
    }

    /**
     * Callback function to receive the result of the chatGetChannels operation.
     * @callback module:api/ChatApi~chatGetChannelsCallback
     * @param {String} error Error message, if any.
     * @param {Array.<module:model/ChatChannel>} data The data returned by the service call.
     * @param {String} response The complete HTTP response.
     */

    /**
     * Get available channels.
     * @param {module:api/ChatApi~chatGetChannelsCallback} callback The callback function, accepting three arguments: error, data, response
     * data is of type: {@link Array.<module:model/ChatChannel>}
     */
    chatGetChannels(callback) {
      let postBody = null;


      let pathParams = {
      };
      let queryParams = {
      };
      let headerParams = {
      };
      let formParams = {
      };

      let authNames = [];
      let contentTypes = ['application/json', 'application/x-www-form-urlencoded'];
      let accepts = ['application/json', 'application/xml', 'text/xml', 'application/javascript', 'text/javascript'];
      let returnType = [ChatChannel];

      return this.apiClient.callApi(
        '/chat/channels', 'GET',
        pathParams, queryParams, headerParams, formParams, postBody,
        authNames, contentTypes, accepts, returnType, callback
      );
    }

    /**
     * Callback function to receive the result of the chatGetConnected operation.
     * @callback module:api/ChatApi~chatGetConnectedCallback
     * @param {String} error Error message, if any.
     * @param {module:model/ConnectedUsers} data The data returned by the service call.
     * @param {String} response The complete HTTP response.
     */

    /**
     * Get connected users.
     * Returns an array with browser users in the first position and API users (bots) in the second position.
     * @param {module:api/ChatApi~chatGetConnectedCallback} callback The callback function, accepting three arguments: error, data, response
     * data is of type: {@link module:model/ConnectedUsers}
     */
    chatGetConnected(callback) {
      let postBody = null;


      let pathParams = {
      };
      let queryParams = {
      };
      let headerParams = {
      };
      let formParams = {
      };

      let authNames = [];
      let contentTypes = ['application/json', 'application/x-www-form-urlencoded'];
      let accepts = ['application/json', 'application/xml', 'text/xml', 'application/javascript', 'text/javascript'];
      let returnType = ConnectedUsers;

      return this.apiClient.callApi(
        '/chat/connected', 'GET',
        pathParams, queryParams, headerParams, formParams, postBody,
        authNames, contentTypes, accepts, returnType, callback
      );
    }

    /**
     * Callback function to receive the result of the chatNew operation.
     * @callback module:api/ChatApi~chatNewCallback
     * @param {String} error Error message, if any.
     * @param {module:model/Chat} data The data returned by the service call.
     * @param {String} response The complete HTTP response.
     */

    /**
     * Send a chat message.
     * @param {String} message 
     * @param {Object} opts Optional parameters
     * @param {Number} opts.channelID Channel to post to. Default 1 (English). (default to 1)
     * @param {module:api/ChatApi~chatNewCallback} callback The callback function, accepting three arguments: error, data, response
     * data is of type: {@link module:model/Chat}
     */
    chatNew(message, opts, callback) {
      opts = opts || {};
      let postBody = null;

      // verify the required parameter 'message' is set
      if (message === undefined || message === null) {
        throw new Error("Missing the required parameter 'message' when calling chatNew");
      }


      let pathParams = {
      };
      let queryParams = {
      };
      let headerParams = {
      };
      let formParams = {
        'message': message,
        'channelID': opts['channelID']
      };

      let authNames = ['apiKey', 'apiNonce', 'apiSignature'];
      let contentTypes = ['application/json', 'application/x-www-form-urlencoded'];
      let accepts = ['application/json', 'application/xml', 'text/xml', 'application/javascript', 'text/javascript'];
      let returnType = Chat;

      return this.apiClient.callApi(
        '/chat', 'POST',
        pathParams, queryParams, headerParams, formParams, postBody,
        authNames, contentTypes, accepts, returnType, callback
      );
    }


}