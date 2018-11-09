// Auto-generated. Do not edit!

// (in-package custom_msg_pkg.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;
let EziServoStatus = require('./EziServoStatus.js');
let EziServoActualMotion = require('./EziServoActualMotion.js');

//-----------------------------------------------------------

class EziServoData {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.ipAddress = null;
      this.status = null;
      this.actualMotion = null;
    }
    else {
      if (initObj.hasOwnProperty('ipAddress')) {
        this.ipAddress = initObj.ipAddress
      }
      else {
        this.ipAddress = '';
      }
      if (initObj.hasOwnProperty('status')) {
        this.status = initObj.status
      }
      else {
        this.status = new EziServoStatus();
      }
      if (initObj.hasOwnProperty('actualMotion')) {
        this.actualMotion = initObj.actualMotion
      }
      else {
        this.actualMotion = new EziServoActualMotion();
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type EziServoData
    // Serialize message field [ipAddress]
    bufferOffset = _serializer.string(obj.ipAddress, buffer, bufferOffset);
    // Serialize message field [status]
    bufferOffset = EziServoStatus.serialize(obj.status, buffer, bufferOffset);
    // Serialize message field [actualMotion]
    bufferOffset = EziServoActualMotion.serialize(obj.actualMotion, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type EziServoData
    let len;
    let data = new EziServoData(null);
    // Deserialize message field [ipAddress]
    data.ipAddress = _deserializer.string(buffer, bufferOffset);
    // Deserialize message field [status]
    data.status = EziServoStatus.deserialize(buffer, bufferOffset);
    // Deserialize message field [actualMotion]
    data.actualMotion = EziServoActualMotion.deserialize(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += object.ipAddress.length;
    return length + 23;
  }

  static datatype() {
    // Returns string type for a message object
    return 'custom_msg_pkg/EziServoData';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '70843f32172de7329088dc42b06b7545';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
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
    const resolved = new EziServoData(null);
    if (msg.ipAddress !== undefined) {
      resolved.ipAddress = msg.ipAddress;
    }
    else {
      resolved.ipAddress = ''
    }

    if (msg.status !== undefined) {
      resolved.status = EziServoStatus.Resolve(msg.status)
    }
    else {
      resolved.status = new EziServoStatus()
    }

    if (msg.actualMotion !== undefined) {
      resolved.actualMotion = EziServoActualMotion.Resolve(msg.actualMotion)
    }
    else {
      resolved.actualMotion = new EziServoActualMotion()
    }

    return resolved;
    }
};

module.exports = EziServoData;
