// Auto-generated. Do not edit!

// (in-package custom_msg_pkg.srv)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------


//-----------------------------------------------------------

class ChangeStateServiceMsgRequest {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.targetState = null;
      this.callerId = null;
    }
    else {
      if (initObj.hasOwnProperty('targetState')) {
        this.targetState = initObj.targetState
      }
      else {
        this.targetState = 0;
      }
      if (initObj.hasOwnProperty('callerId')) {
        this.callerId = initObj.callerId
      }
      else {
        this.callerId = 0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type ChangeStateServiceMsgRequest
    // Serialize message field [targetState]
    bufferOffset = _serializer.int32(obj.targetState, buffer, bufferOffset);
    // Serialize message field [callerId]
    bufferOffset = _serializer.int32(obj.callerId, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type ChangeStateServiceMsgRequest
    let len;
    let data = new ChangeStateServiceMsgRequest(null);
    // Deserialize message field [targetState]
    data.targetState = _deserializer.int32(buffer, bufferOffset);
    // Deserialize message field [callerId]
    data.callerId = _deserializer.int32(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 8;
  }

  static datatype() {
    // Returns string type for a service object
    return 'custom_msg_pkg/ChangeStateServiceMsgRequest';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'ab4ca4991a5634318e6eeaa0eb1a11c8';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    int32 targetState
    int32 callerId
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new ChangeStateServiceMsgRequest(null);
    if (msg.targetState !== undefined) {
      resolved.targetState = msg.targetState;
    }
    else {
      resolved.targetState = 0
    }

    if (msg.callerId !== undefined) {
      resolved.callerId = msg.callerId;
    }
    else {
      resolved.callerId = 0
    }

    return resolved;
    }
};

class ChangeStateServiceMsgResponse {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.result = null;
      this.errorDesc = null;
    }
    else {
      if (initObj.hasOwnProperty('result')) {
        this.result = initObj.result
      }
      else {
        this.result = 0;
      }
      if (initObj.hasOwnProperty('errorDesc')) {
        this.errorDesc = initObj.errorDesc
      }
      else {
        this.errorDesc = '';
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type ChangeStateServiceMsgResponse
    // Serialize message field [result]
    bufferOffset = _serializer.int32(obj.result, buffer, bufferOffset);
    // Serialize message field [errorDesc]
    bufferOffset = _serializer.string(obj.errorDesc, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type ChangeStateServiceMsgResponse
    let len;
    let data = new ChangeStateServiceMsgResponse(null);
    // Deserialize message field [result]
    data.result = _deserializer.int32(buffer, bufferOffset);
    // Deserialize message field [errorDesc]
    data.errorDesc = _deserializer.string(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += object.errorDesc.length;
    return length + 8;
  }

  static datatype() {
    // Returns string type for a service object
    return 'custom_msg_pkg/ChangeStateServiceMsgResponse';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '97ca5a82af8b07afaf006f10bd1c483d';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    int32 result
    string errorDesc
    
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new ChangeStateServiceMsgResponse(null);
    if (msg.result !== undefined) {
      resolved.result = msg.result;
    }
    else {
      resolved.result = 0
    }

    if (msg.errorDesc !== undefined) {
      resolved.errorDesc = msg.errorDesc;
    }
    else {
      resolved.errorDesc = ''
    }

    return resolved;
    }
};

module.exports = {
  Request: ChangeStateServiceMsgRequest,
  Response: ChangeStateServiceMsgResponse,
  md5sum() { return 'e7cf3a237ea1ba28a266b276ffbdbbae'; },
  datatype() { return 'custom_msg_pkg/ChangeStateServiceMsg'; }
};
