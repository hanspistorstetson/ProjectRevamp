#221 Project - Rails Revamp
We created a project in my CSCI-221 class which was basically a tracker for events. Eventgoers are generated a QR code that they use to check in at various points in order to collect data. It could also be used as lunch passes, etc

# Planning our application
1. Answer Questions
	- What are we building?
	- Who are we building it for?
	- What features do we need to have?
2. User Stories
3. Model our Data
4. Think through the pages we need in our app

## Questions

1. What are we building? We are building a public site. A place for event hosters to maintain a database of all people attending and a place for attendees to manage their accounts, get their QR codes, and see what events are available
2. Who are we building it for? We are building it for event hosters in order to make their lives easier in tracking their attendees and for the attendees to reduce the amount of things they have to keep track of.
3.  What features do we want to have?
	- User(devise)
	- Events _has\_many Activities_
	- Activity _belongs\_event_
	- Sign up to be a User
	- Sign up as a hoster
	- As a user, sign up for various events
	- As a hoster, create events and create activities within these events

## User Stories
As a blank, I want to be able to blank, so that blank.
- As a user, I want to be able to have CRUD functionality
- As a user, I want to be able to sign up for events
- As a hoster, I want to have CRUD functionality
- As a hoster, I want to be able to create events and activities

## Modeling our Data

**Event**
	title:string
	description:text
	dateof:date
	
**Activity**
	title:string
	description:text
	
**Checkin**
	time:date
	
**User**

## Think through the pages we need in our app

- Home
- User#Show
- User#edit
- Event#index
- Event#show
- 