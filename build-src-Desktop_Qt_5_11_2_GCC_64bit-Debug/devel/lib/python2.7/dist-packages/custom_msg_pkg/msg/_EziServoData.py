# This Python file uses the following encoding: utf-8
"""autogenerated by genpy from custom_msg_pkg/EziServoData.msg. Do not edit."""
import sys
python3 = True if sys.hexversion > 0x03000000 else False
import genpy
import struct

import custom_msg_pkg.msg

class EziServoData(genpy.Message):
  _md5sum = "70843f32172de7329088dc42b06b7545"
  _type = "custom_msg_pkg/EziServoData"
  _has_header = False #flag to mark the presence of a Header object
  _full_text = """string ipAddress
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

"""
  __slots__ = ['ipAddress','status','actualMotion']
  _slot_types = ['string','custom_msg_pkg/EziServoStatus','custom_msg_pkg/EziServoActualMotion']

  def __init__(self, *args, **kwds):
    """
    Constructor. Any message fields that are implicitly/explicitly
    set to None will be assigned a default value. The recommend
    use is keyword arguments as this is more robust to future message
    changes.  You cannot mix in-order arguments and keyword arguments.

    The available fields are:
       ipAddress,status,actualMotion

    :param args: complete set of field values, in .msg order
    :param kwds: use keyword arguments corresponding to message field names
    to set specific fields.
    """
    if args or kwds:
      super(EziServoData, self).__init__(*args, **kwds)
      #message fields cannot be None, assign default values for those that are
      if self.ipAddress is None:
        self.ipAddress = ''
      if self.status is None:
        self.status = custom_msg_pkg.msg.EziServoStatus()
      if self.actualMotion is None:
        self.actualMotion = custom_msg_pkg.msg.EziServoActualMotion()
    else:
      self.ipAddress = ''
      self.status = custom_msg_pkg.msg.EziServoStatus()
      self.actualMotion = custom_msg_pkg.msg.EziServoActualMotion()

  def _get_types(self):
    """
    internal API method
    """
    return self._slot_types

  def serialize(self, buff):
    """
    serialize message into buffer
    :param buff: buffer, ``StringIO``
    """
    try:
      _x = self.ipAddress
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      buff.write(struct.pack('<I%ss'%length, length, _x))
      _x = self
      buff.write(_get_struct_6B2ibi().pack(_x.status.connected, _x.status.enabled, _x.status.alarm, _x.status.emergency, _x.status.stopping, _x.status.moving, _x.actualMotion.position, _x.actualMotion.velocity, _x.actualMotion.direction, _x.actualMotion.positionError))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(locals().get('_x', self)))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(locals().get('_x', self)))))

  def deserialize(self, str):
    """
    unpack serialized message in str into this message instance
    :param str: byte array of serialized message, ``str``
    """
    try:
      if self.status is None:
        self.status = custom_msg_pkg.msg.EziServoStatus()
      if self.actualMotion is None:
        self.actualMotion = custom_msg_pkg.msg.EziServoActualMotion()
      end = 0
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.ipAddress = str[start:end].decode('utf-8')
      else:
        self.ipAddress = str[start:end]
      _x = self
      start = end
      end += 19
      (_x.status.connected, _x.status.enabled, _x.status.alarm, _x.status.emergency, _x.status.stopping, _x.status.moving, _x.actualMotion.position, _x.actualMotion.velocity, _x.actualMotion.direction, _x.actualMotion.positionError,) = _get_struct_6B2ibi().unpack(str[start:end])
      self.status.connected = bool(self.status.connected)
      self.status.enabled = bool(self.status.enabled)
      self.status.alarm = bool(self.status.alarm)
      self.status.emergency = bool(self.status.emergency)
      self.status.stopping = bool(self.status.stopping)
      self.status.moving = bool(self.status.moving)
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e) #most likely buffer underfill


  def serialize_numpy(self, buff, numpy):
    """
    serialize message with numpy array types into buffer
    :param buff: buffer, ``StringIO``
    :param numpy: numpy python module
    """
    try:
      _x = self.ipAddress
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      buff.write(struct.pack('<I%ss'%length, length, _x))
      _x = self
      buff.write(_get_struct_6B2ibi().pack(_x.status.connected, _x.status.enabled, _x.status.alarm, _x.status.emergency, _x.status.stopping, _x.status.moving, _x.actualMotion.position, _x.actualMotion.velocity, _x.actualMotion.direction, _x.actualMotion.positionError))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(locals().get('_x', self)))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(locals().get('_x', self)))))

  def deserialize_numpy(self, str, numpy):
    """
    unpack serialized message in str into this message instance using numpy for array types
    :param str: byte array of serialized message, ``str``
    :param numpy: numpy python module
    """
    try:
      if self.status is None:
        self.status = custom_msg_pkg.msg.EziServoStatus()
      if self.actualMotion is None:
        self.actualMotion = custom_msg_pkg.msg.EziServoActualMotion()
      end = 0
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.ipAddress = str[start:end].decode('utf-8')
      else:
        self.ipAddress = str[start:end]
      _x = self
      start = end
      end += 19
      (_x.status.connected, _x.status.enabled, _x.status.alarm, _x.status.emergency, _x.status.stopping, _x.status.moving, _x.actualMotion.position, _x.actualMotion.velocity, _x.actualMotion.direction, _x.actualMotion.positionError,) = _get_struct_6B2ibi().unpack(str[start:end])
      self.status.connected = bool(self.status.connected)
      self.status.enabled = bool(self.status.enabled)
      self.status.alarm = bool(self.status.alarm)
      self.status.emergency = bool(self.status.emergency)
      self.status.stopping = bool(self.status.stopping)
      self.status.moving = bool(self.status.moving)
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e) #most likely buffer underfill

_struct_I = genpy.struct_I
def _get_struct_I():
    global _struct_I
    return _struct_I
_struct_6B2ibi = None
def _get_struct_6B2ibi():
    global _struct_6B2ibi
    if _struct_6B2ibi is None:
        _struct_6B2ibi = struct.Struct("<6B2ibi")
    return _struct_6B2ibi
