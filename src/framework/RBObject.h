/** -*-objc-*-
 *
 *   $Id$
 *
 *   Copyright (c) 2001 FUJIMOTO Hisakuni <hisa@imasy.or.jp>
 *
 *   This program is free software.
 *   You can distribute/modify this program under the terms of
 *   the GNU Lesser General Public License version 2.
 *
 **/
#import <Foundation/NSProxy.h>
#import <Foundation/NSMethodSignature.h>
#import <Foundation/NSInvocation.h>
#import <LibRuby/cocoa_ruby.h>

@interface RBObject : NSProxy
{
  VALUE m_rbobj;
}

- initWithRubyObject: (VALUE) rbobj;
- (VALUE) __rbobj__;

@end

@interface RBObject(RBSlaveObject)
- init;
- initWithMasterObject: master;
- initWithClass: (Class)occlass;
- initWithClass: (Class)occlass masterObject: master;
- initWithClass: (Class)occlass withArg: (VALUE)arg masterObject: master;
- initWithRubyClass: (VALUE)rbclass;
- initWithRubyClass: (VALUE)rbclass masterObject: master;
- initWithRubyClass: (VALUE)rbclass withArg: (VALUE)arg masterObject: master;
@end
