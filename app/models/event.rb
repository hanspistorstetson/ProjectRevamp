class Event < ApplicationRecord
  validates :dateof, presence: true
  has_many :activities
  has_many :signups
  has_many :users, :through => :signups
end
