class User < ApplicationRecord
  # Include default devise modules. Others available are:
  # :confirmable, :lockable, :timeoutable and :omniauthable
  devise :database_authenticatable, :registerable,
         :recoverable, :rememberable, :trackable, :validatable
  has_many :checkins
  has_many :activities, :through => :checkins
  has_many :signups
  has_many :events, :through => :signups
end
