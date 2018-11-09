// Auto-generated. Do not edit!

// (in-package custom_msg_pkg.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;
let EziServoData = require('./EziServoData.js');

//-----------------------------------------------------------

class EziServosData {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.eziServoData = null;
    }
    else {
      if (initObj.hasOwnProperty('eziServoData')) {
        this.eziServoData = initObj.eziServoData
      }
      else {
        this.eziServoData = [];
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type EziServosData
    // Serialize message field [eziServoData]
    // Serialize the length for message field [eziServoData]
    bufferOffset = _serializer.uint32(obj.eziServoData.length, buffer, bufferOffset);
    obj.eziServoData.forEach((val) => {
      bufferOffset = EziServoData.serialize(val, buffer, bufferOffset);
    });
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type EziServosData
    let len;
    let data = new EziServosData(null);
    // Deserialize message field [eziServoData]
    // Deserialize array length for message field [eziServoData]
    len = _deserializer.uint32(buffer, bufferOffset);
    data.eziServoData = new Array(len);
    for (let i = 0; i < len; ++i) {
      data.eziServoData[i] = EziServoData.deserialize(buffer, bufferOffset)
    }
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    object.eziServoData.forEach((val) => {
      length += EziServoData.getMessageSize(val);
    });
    return length + 4;
  }

  static datatype() {
    // Returns string type for a message object
    return 'custom_msg_pkg/EziServosData';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'a1386091f448a56ae9b0d394c1619d91';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    EziServoData[] eziServoData
    
    ================================================================================
    MSG: custom_msg_pkg/EziServoData
    string ipAddress
    EziServoStatus status
    EziServoActualMotion actualMotion
    
    
    ================================================================================
    MSG: custom_msg_pkg/EziServoStatus
    bool connected
    bool enabled
    bool alarm
    bool emergency
    bool stopping 
    bool moving
    
    
    
    ================================================================================
    MSG: custom_msg_pkg/EziServoActualMotion
    int32 position
    int32 velocity
    int8 direction
    int32 positionError
    
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new EziServosData(null);
    if (msg.eziServoData !== undefined) {
      resolved.eziServoData = new Array(msg.eziServoData.length);
      for (let i = 0; i < resolved.eziServoData.length; ++i) {
        resolved.eziServoData[i] = EziServoData.Resolve(msg.eziServoData[i]);
      }
    }
    else {
      resolved.eziServoData = []
    }

    return resolved;
    }
};

module.exports = EziServosData;
