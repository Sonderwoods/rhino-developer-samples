#pragma once

class CSampleAttributeUserData : public ON_UserData
{
  // Opennurbs classes that are saved in .3dm files require
  // an ON_OBJECT_DECLARE call in their declaration.
  ON_OBJECT_DECLARE(CSampleAttributeUserData);

public:

  /*
  Returns:
    Uuid used to identify this type of user data.
    This is the value saved in m_userdata_uuid and
    passed to ON_Object::GetUserData().
  */
  static ON_UUID Id();

  CSampleAttributeUserData();
  ~CSampleAttributeUserData();

  // NOTE WELL:
  //   Because the members of this class are class are types 
  //   that have fully functional copy constructors and 
  //   operator=s, it is NOT necessary to provide an explicit
  //   a copy constructor and operator=.  In fact, it would 
  //   be best to use the ones C++ generates. 
  //   They are included in this example to demonstrate the
  //   correct way to implement a copy constructor and
  //   operator= because this is a task that trips up
  //   many people that attempt to implement them.
  CSampleAttributeUserData(const CSampleAttributeUserData& src);
  CSampleAttributeUserData& operator=(const CSampleAttributeUserData& src);

  // override virtual ON_UserData::GetDescription()
  bool GetDescription(ON_wString& description) override;

  // override virtual ON_UserData::Archive()
  bool Archive() const override;

  // override virtual ON_UserData::Write()
  bool Write(
    ON_BinaryArchive& binary_archive
  ) const override;

  // override virtual ON_UserData::Read()
  bool Read(
    ON_BinaryArchive& binary_archive
  ) override;

public:
  ON_wString m_my_string;
  ON_3dPoint m_my_point;
};
