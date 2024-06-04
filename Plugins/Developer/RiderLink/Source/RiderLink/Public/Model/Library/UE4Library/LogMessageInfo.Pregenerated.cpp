//------------------------------------------------------------------------------
// <auto-generated>
//     This code was generated by a RdGen v1.11.
//
//     Changes to this file may cause incorrect behavior and will be lost if
//     the code is regenerated.
// </auto-generated>
//------------------------------------------------------------------------------
#include "LogMessageInfo.Pregenerated.h"



#ifdef _MSC_VER
#pragma warning( push )
#pragma warning( disable:4250 )
#pragma warning( disable:4307 )
#pragma warning( disable:4267 )
#pragma warning( disable:4244 )
#pragma warning( disable:4100 )
#endif

namespace JetBrains {
namespace EditorPlugin {
// companion
// constants
// initializer
void LogMessageInfo::initialize()
{
}
// primary ctor
LogMessageInfo::LogMessageInfo(ELogVerbosity::Type type_, FString category_, rd::optional<rd::DateTime> time_) :
rd::IPolymorphicSerializable()
,type_(std::move(type_)), category_(std::move(category_)), time_(std::move(time_))
{
    initialize();
}
// secondary constructor
// default ctors and dtors
// reader
LogMessageInfo LogMessageInfo::read(rd::SerializationCtx& ctx, rd::Buffer & buffer)
{
    auto type_ = rd::Polymorphic<ELogVerbosity::Type>::read(ctx, buffer);
    auto category_ = rd::Polymorphic<FString>::read(ctx, buffer);
    auto time_ = buffer.read_nullable<rd::DateTime>(
    [&ctx, &buffer]() mutable  
    { return buffer.read_date_time(); }
    );
    LogMessageInfo res{std::move(type_), std::move(category_), std::move(time_)};
    return res;
}
// writer
void LogMessageInfo::write(rd::SerializationCtx& ctx, rd::Buffer& buffer) const
{
    rd::Polymorphic<ELogVerbosity::Type>::write(ctx, buffer, type_);
    rd::Polymorphic<std::decay_t<decltype(category_)>>::write(ctx, buffer, category_);
    buffer.write_nullable<rd::DateTime>(time_, 
    [&ctx, &buffer](rd::DateTime const & it) mutable  -> void 
    { buffer.write_date_time(it); }
    );
}
// virtual init
// identify
// getters
ELogVerbosity::Type const & LogMessageInfo::get_type() const
{
    return type_;
}
FString const & LogMessageInfo::get_category() const
{
    return category_;
}
rd::optional<rd::DateTime> const & LogMessageInfo::get_time() const
{
    return time_;
}
// intern
// equals trait
bool LogMessageInfo::equals(rd::ISerializable const& object) const
{
    auto const &other = dynamic_cast<LogMessageInfo const&>(object);
    if (this == &other) return true;
    if (this->type_ != other.type_) return false;
    if (this->category_ != other.category_) return false;
    if (this->time_ != other.time_) return false;
    
    return true;
}
// equality operators
bool operator==(const LogMessageInfo &lhs, const LogMessageInfo &rhs) {
    if (lhs.type_name() != rhs.type_name()) return false;
    return lhs.equals(rhs);
}
bool operator!=(const LogMessageInfo &lhs, const LogMessageInfo &rhs){
    return !(lhs == rhs);
}
// hash code trait
size_t LogMessageInfo::hashCode() const noexcept
{
    size_t __r = 0;
    __r = __r * 31 + (rd::hash<ELogVerbosity::Type>()(get_type()));
    __r = __r * 31 + (rd::hash<FString>()(get_category()));
    __r = __r * 31 + ((static_cast<bool>(get_time())) ? rd::hash<rd::DateTime>()(*get_time()) : 0);
    return __r;
}
// type name trait
std::string LogMessageInfo::type_name() const
{
    return "LogMessageInfo";
}
// static type name trait
std::string LogMessageInfo::static_type_name()
{
    return "LogMessageInfo";
}
// polymorphic to string
std::string LogMessageInfo::toString() const
{
    std::string res = "LogMessageInfo\n";
    res += "\ttype = ";
    res += rd::to_string(type_);
    res += '\n';
    res += "\tcategory = ";
    res += rd::to_string(category_);
    res += '\n';
    res += "\ttime = ";
    res += rd::to_string(time_);
    res += '\n';
    return res;
}
// external to string
std::string to_string(const LogMessageInfo & value)
{
    return value.toString();
}
}
}

#ifdef _MSC_VER
#pragma warning( pop )
#endif

